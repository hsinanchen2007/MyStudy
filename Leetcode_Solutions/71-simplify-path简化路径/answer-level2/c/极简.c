```
#define FNMC_MAX 100
#define PATH_MAX 25600

char *simplifyPath(char *path)
{
	if (NULL == path || *path != '/')
		return NULL;
	
	char *s = malloc(sizeof(char) * PATH_MAX);
	int fnms_index[FNMC_MAX];
	int sp = 0;
	
	s[0] = '/';
	fnms_index[sp++] = 1;

	while (*path != '\0') { // *path = '\0' or '/', s = "/" or "/xxx"
		while ('/' == *path)
			++path;
		int srt = fnms_index[sp - 1], stp = srt;
		while (*path != '\0' && *path != '/')
			s[stp++] = *path++;
		if (stp - srt > 0) {
			if (stp - srt == 1 && '.' == s[srt])
				; // null statement
			else if (stp - srt == 2 && '.' == s[srt] && '.' == s[srt + 1]) {
				if (sp > 1)
					--sp;
			} else {
				if (sp > 1) {
					for (int idx = stp; idx > srt; --idx)
						s[idx] = s[idx - 1];
					s[srt] = '/';
					++stp;
				}
				fnms_index[sp++] = stp;
			}
		}
	}

	s[fnms_index[sp - 1]] = '\0';
	return s;
}
```