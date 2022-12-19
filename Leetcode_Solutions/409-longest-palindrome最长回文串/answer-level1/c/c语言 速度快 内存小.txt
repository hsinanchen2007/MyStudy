### 解题思路
1.统计所有字母出现的个数存在数组里，避免麻烦直接buf[128] 因为：A-Z 65-90 a-z 97-122
2.从数组下标65开始，遇到偶数直接加，遇到奇数先加后减一。
3.判断是否有奇数存在，存在就加一；

### 代码

```c
int longestPalindrome(char * s){
    int buf[128] = {0};
    int i = 0;
    int max_len = 0;
    int flag = 0;
    for(i = 0; i < strlen(s); ++i)
    {
        buf[s[i]] += 1; 
    }

    for(i = 65; i< 128; ++i)
    {
        if(buf[i] > 0)
        {
            if(buf[i] % 2 == 0)
                max_len += buf[i];
            else
            { 
                flag = 1;  // 判断是否有奇数存在
                if(buf[i] > 1)
                {
                    max_len += buf[i] - 1; 
                }
            } 
        }
    }
    if(flag == 1)
        max_len += 1;
    return (max_len);
}
```