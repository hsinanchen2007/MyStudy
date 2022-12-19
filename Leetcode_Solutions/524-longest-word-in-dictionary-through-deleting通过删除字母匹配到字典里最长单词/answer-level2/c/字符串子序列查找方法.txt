






```

static int dict_index;
static int maxlen;
#define BIGGER 1
#define EQUAL 0
#define SMALL -1
/*************************字典序比较**********************/
int compare_dict(char *l, char *r) {
	int llen = strlen(l);
	int rlen = strlen(r);
	
	if (!strcmp(l, r)) {
		return EQUAL;
	}
	
	int i = 0,j = 0;
	while (i < llen && j < rlen) {
		if (l[i] > r[j]) {
			return BIGGER;
		}
		
		if (l[i] < r[j]) {
			return SMALL;
		}
		j++;
		i++;
	}
	if (llen == rlen) {
		return EQUAL;
	}
	
	if (llen > rlen) {
		return BIGGER;
	}
	return SMALL;
}

int finddict(char *s, char *dict) {
	
	int i, j;
	
	int dlen = strlen(dict);
	int slen = strlen(s);
	
	i = 0;
	j = 0;
	
	while ((i < slen) && (j < dlen)) {
		if (dict[j] == s[i]) {
			i++;
			j++;
		}
		else {
			i++;
		}
	}
	
	if (j < dlen) {
		return -1;
	}
	return dlen;
}

int findmaxdict(char * s, char ** d, int dSize) {
	dict_index = -1;
	maxlen = -1;
	
	int i;
	int ret;
	
	for (i = 0; i < dSize; i++) {
		ret = finddict(s, d[i]);
		if (ret > 0) {
			if (dict_index == -1) {
				dict_index = i;
				maxlen = ret;
			} else {
				if (maxlen < ret) {
					dict_index = i;
					maxlen = ret;
					
				} else if (maxlen == ret) {
					int ret2 = compare_dict(d[i], d[dict_index]);
					if (ret2 == SMALL) {
						dict_index = i;
					}
				} else {
					;
				}
			}
		}
	}
	return dict_index;
}

char * findLongestWord(char * s, char ** d, int dSize){
	int i;

	i = findmaxdict(s, d, dSize);
	if (i < 0) {
		return "";
	}
	return d[dict_index];
}


```
