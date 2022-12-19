### 解题思路
cnt:字符个数。统计字符重复个数，若cnt为奇数，cnt=cnt-1;
count:最长回文数。count统计每个cnt，若count小于字符串长度，可以在中间添加一个字符，count=count+1；
通过双层for循环遍历字符串，若出现相同字符cnt+1,并将其赋值为'0'（通过'0'标识字符已出现，跳过循环，减少时间）。
![最长回文数.png](https://pic.leetcode-cn.com/3d1ef776c808bba0d2de729d1e6598f13c891585148057e0b89ee89bd7812b67-%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E6%95%B0.png)

### 代码

```c
int longestPalindrome(char * s){
    int cnt, count, L, i, j;
    count = 0;
    cnt = 0;
    L = strlen(s);
    for(i=0;i<L;i++)
    {
        if(s[i] == '0')
            continue;
        cnt = 1;
        for(j=i+1;j<L;j++)
        {
            if(s[j] == s[i])
            {
                s[j] = '0';
                cnt += 1;
            }
                
        }
        cnt = cnt % 2 ? (cnt-1):cnt;
        count += cnt;
    }
    if(count < L)
        return count + 1;
    return count;
}
```