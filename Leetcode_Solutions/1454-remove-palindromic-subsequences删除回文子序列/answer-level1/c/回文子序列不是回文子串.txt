### 解题思路
![image.png](https://pic.leetcode-cn.com/e7a1cdf30880a16042618c25b5dd759d5485f39076565d67a3fdef0c4a36ad74-image.png)


### 代码

```c
int removePalindromeSub(char * s){
    
    int len = strlen(s);

    if(0 == len)
    {
        return 0;
    }
    
    int left = 0 ;
    int right = len - 1;

    while(left < right)
    {
        if(s[left] != s[right])
        {
            return 2;
        }

        left++;
        right--;
    }

    return  1;
}
```