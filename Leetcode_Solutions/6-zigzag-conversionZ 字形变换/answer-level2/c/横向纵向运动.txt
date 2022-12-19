使用二维数组Arr[j]k存储，分为两种情况：
1.纵向运动，判断依据为k % (numRows - 1) == 0,此种情况又分为两种：
a>j == numRows - 1,此处为转折点，需要调整运动方向为横向，即j--，k++
b>j < numRows - 1，保持横向运动即可，即j++
2.横向运动，判断依据为k % (numRows - 1) != 0,该情况只存在一种可能即整体向右上方运动，只需要A[j--][k++] = s[i]即可**（注意j是减而非增）**
			char * convert(char * s, int numRows){
				int len = strlen(s) + 1;
				char* retStr = (char*)malloc(sizeof(char) * len);
				retStr[0] = '\0';
				if(numRows == 0 || numRows == 1) {
					strcpy(retStr, s);
					return retStr;
				}
				char Arr[numRows][len];
				int i;
				for (i = 0; i < numRows; i++) {
					memset(Arr[i], '\0', len);
				}
				int j = 0, k = 0;
				i = 0; 
				while (s[i] != '\0') {
					if (k % (numRows - 1) == 0) { //表示水平方向上在竖线上
						Arr[j][k] = s[i];
						if (j == numRows - 1) {
							j--;
							k++; 
						} else {
							j++;
						}               
					} else {
						Arr[j--][k++] = s[i];
					}
					i++;
				}
			
				k = 0;
				for (i = 0; i < numRows; i++) {
					for (j = 0; j < len; j++) {
						if (Arr[i][j] != '\0') {
							retStr[k++] = Arr[i][j];
						}
					}
				}
				retStr[k] = '\0';
			
				return retStr;
			}