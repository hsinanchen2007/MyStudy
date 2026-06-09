char * longestCommonPrefix(char ** strs, int strsSize){
	if (strsSize <= 0) {
		char *ret = (char *)calloc(1, sizeof(char));
		if (ret == NULL) {
			exit(-1);
		}
		return ret;
	}
	int len = (int)strlen(strs[0]);
	if(strsSize == 1) {
		char *ret = (char *)calloc(len + 1, sizeof(char));
		if (ret == NULL) {
			exit(-1);
		}
		strcpy(ret, strs[0]);
		return ret;

	}
	int k = 0;
	int flg = 0;
	while (k < len) {
		for (int j = 0; j < strsSize - 1; j++) {
			if (strs[j][k] == '\0') {
				flg = 1;
				break;
			}
			if (strs[j + 1][k] != strs[j][k]) {
				flg = 1;
				break;
			}	
		}
		if (flg) {
			break;
		}
		k++;
	}
	char *ret = (char *)calloc( k + 1, sizeof(char));
	if (ret == NULL) {
		exit(-1);
	}
	if (k == 0) {
		return ret;
	}
	strncpy(ret, strs[0], k);
	return ret;
}