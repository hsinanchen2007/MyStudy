利用之前已经得到的max，如果回文个数已经少于max个，就走不到max < (j - i + 1)，没必要再进入

char * longestPalindrome(char * s){
    int length = strlen(s);
	int i,j;
	int max = 0;
	int num;
	int start = 0;
	
	
	for (i = 0; i < length; i++){
		for (j = (length - 1); j >= i + max - 1; j--) { //利用之前已经得到的max，如果回文个数已经少于max个，就走不到max < (j - i + 1)，没必要再进入
			num = 0;
			while(s[i + num] == s[j - num]) {
				num++;
				if ((i + num) >= (j - num)) {
					if (max < (j - i + 1)) {
						max = j - i + 1;
						start = i;
					}
					break;
				}
			}
				
		}		
	}
	char *result = (char *)malloc(max + 1);
	for(i = 0; i < max; i++){
		result[i] = s[start + i];
	}
	result[i] = '\0';
	return result;
}

