### 解题思路
此处撰写解题思路

### 代码

```c
char * longestPalindrome(char * s){

    if(strlen(s) < 1) return "";

    int left,right;
    int start,end,i;
    int length = strlen(s);
    int maxLength;
    bool dp[length][length];
    start = 0;
    end = 0;

    

    for(i = 0;i < strlen(s);i++){
        dp[i][i] = true;//初始化单个字符为回文串
    }

    for(right = 1;right <= length-1;right++){
        for(left = 0;left < right;left++){
            if(s[left] == s[right] && (right - left == 1 || dp[left+1][right-1] == true)){
                dp[left][right] = true;
                if(right - left > end - start){
                    start = left;
                    end = right;
                }
                continue;
            }

            else dp[left][right] = false;

        }
    }

    maxLength = end - start + 1;

    


    char *arr = (char *)malloc(sizeof(int) * (maxLength * 2));
   	for (i = 0; i < maxLength; i++)
   	{
   		arr[i] = s[start++];
   	}
   	arr[i] = '\0';
   	return arr;


    





}


```