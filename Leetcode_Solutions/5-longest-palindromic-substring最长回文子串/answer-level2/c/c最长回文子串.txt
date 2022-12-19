### 解题思路
4ms 从符文串中间左右遍历 aba型和abba型+剪枝
### 代码

```c
char * longestPalindrome(char * s){

    int len = strlen(s);
    if (!len)
        return s;
    int max = 0;
    int low = len / 2, high = len / 2;
    int flag = 0;
    int maxindex1 = 0, maxindex2 = 0;
    while (low >= 0 || high < len)
    {
        flag = 0;

        if ((low+1 )* 2 < max)
        {
            flag++;
        }
        else
        {
            //从low左开始
            int low1 = low - 1, high1 = low + 1;
            while (low1 >= 0 && high1 <= len - 1 && s[low1] == s[high1])
            {
                low1--;
                high1++;
            }
            low1++;
            high1--;

            int temp = (high1 - low1) + 1;
            if (low1 <= high1 && temp > max)
            {
                max = temp;
                maxindex1 = low1;
                maxindex2 = high1;
            }

            low1 = low-1, high1 = low;
            while (low1 >= 0 && high1 <= len - 1 && s[low1] == s[high1])
            {
                low1--;
                high1++;
            }
            low1++;
            high1--;

            temp = (high1 - low1) + 1;
            if (low1 <= high1 && temp > max)
            {
                max = temp;
                maxindex1 = low1;
                maxindex2 = high1;
            }
        }
        low--;

        if ((len - high+1) * 2 < max)
        {
            flag++;
        }
        else
        {
            //从low右开始
            int low1 = high - 1, high1 = high + 1;
            while (low1 >= 0 && high1 <= len - 1 && s[low1] == s[high1])
            {
                low1--;
                high1++;
            }
            low1++;
            high1--;
            int temp = (high1 - low1) + 1;
            if (low1 < high1 && temp > max)
            {
                max = temp;
                maxindex1 = low1;
                maxindex2 = high1;
            }
            low1 = high, high1 = high + 1;
            while (low1 >= 0 && high1 <= len - 1 && s[low1] == s[high1])
            {
                low1--;
                high1++;
            }
            low1++;
            high1--;
            temp = (high1 - low1) + 1;
            if (low1 < high1 && temp >= max)
            {
                max = temp;
                maxindex1 = low1;
                maxindex2 = high1;
            }
        }
        high++;
    }
    len = maxindex2 - maxindex1 + 2;
    char *str = (char *)malloc(len);
    for (int i = maxindex1, k = 0; i <= maxindex2; i++, k++)
    {
        str[k] = s[i];
    }
    str[len - 1] = '\0';
    return str;
}


```