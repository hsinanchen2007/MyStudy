dp[i]表示下标为i之前连续不重复的个数，start为连续不重复子串的起始位置，每次循环判断s[i]是否在（s[start], s[i - 1]）之间；
1.如果不在（s[start], s[i - 1]）之间，则dp[i] = dp[i - 1] + 1
2.如果在，则start位置移到s[i]在s[start], s[i - 1]之间出现的位置的下一位，例如abcda，那么当s[i] = ‘a’，start = 0，时
start将移到start + 1的位置上即start = start + 1。

			bool isValid(char ch, char* arr, int arrSize, int* start){
				int i;
				for (i = 0; i < arrSize; i++) {
					if (ch == arr[i]) {
						*start = i;
						return false;
					}
				}
			
				return true;
			}
			
			int lengthOfLongestSubstring(char * s){
				int dp[50000]; //dp[i]表示以i为结尾的最长子串个数
				if (s[0] == '\0') {
					return 0;
				}
				if (strlen(s) == 1) {
					return 1;
				}
				int maxLength = 0; //最长不重复子串
			
				int start = 0;
				dp[0] = 1;
				int i;
				int* newStart = (int*)malloc(sizeof(int));
				for (i = 1; s[i] != '\0'; i++) {
					*newStart = 0; 
					if (isValid(s[i], s + start, dp[i - 1], newStart)) {
						dp[i] = dp[i - 1] + 1;
						maxLength = dp[i] > maxLength ? dp[i] : maxLength;
					} else {
						dp[i] = i - (*newStart + start);
						start = start + *newStart + 1;
						maxLength = dp[i - 1] > maxLength ? dp[i - 1] : maxLength;
					}
				}
			
				free(newStart);
				return maxLength;
			}




