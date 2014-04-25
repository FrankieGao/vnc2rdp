#include <stdlib.h>
#include <string.h>

#include "sec.h"

static int
r2v_sec_build_conn(int client_fd, r2v_sec_t *s)
{
	return 0;
}

r2v_sec_t *
r2v_sec_init(int client_fd)
{
	r2v_sec_t *s = NULL;

	s = (r2v_sec_t *)malloc(sizeof(r2v_sec_t));
	if (s == NULL) {
		goto fail;
	}
	memset(s, 0, sizeof(r2v_sec_t));

	s->mcs = r2v_mcs_init(client_fd);
	if (s->mcs == NULL) {
		goto fail;
	}

	if (r2v_sec_build_conn(client_fd, s) == -1) {
		goto fail;
	}

	return s;

fail:
	r2v_sec_destory(s);
	return NULL;
}

void
r2v_sec_destory(r2v_sec_t *s)
{
	if (s == NULL) {
		return;
	}
	if (s->mcs != NULL) {
		r2v_mcs_destory(s->mcs);
	}
	free(s);
}
