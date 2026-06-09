### 解题思路
这题比较简单，比的是代码实现的速度。我用了32mins。
思路很简单：
（1）所有出现偶数次的字母，都算进去；
（2）奇数次出现的字母，除了第一次出现的字母外，其他字母次数减1算进去。
![image.png](https://pic.leetcode-cn.com/c0aafc93dbd4a8f98ac2597890f85c73cdb068cab766e5b0793f2bdf03ab4e99-image.png)


### 代码

```c
int longestPalindrome(char * s){
    int len = strlen(s);
    int i = 0;
    int counts[200] = {0};
    int ret = 0;
    int x = 0;
    int first_odd = 0;
    //printf("A = %d, Z = %d, a =%d, z = %d\n",'A', 'Z', 'a', 'z');
    for(i = 0 ; i < len; i++) {
        x = (int)(s[i] - 'A');
        //printf("x = %d, s[%d] = %c\n",x, i, s[i]);
        counts[x] = counts[x] + 1;
    }

    for(i = 0; i < 200; i++) {
        if(counts[i] % 2 == 0) {
            ret = ret + counts[i];
        }
        else {
            if(counts[i] > 1) {
                if(first_odd == 0) {
                    ret = ret + 1;
                    first_odd = 1;
                }
                ret = ret + counts[i] - 1;
            }
            else {
                if(first_odd == 0) {
                    ret = ret + 1;
                    first_odd = 1;
                }                
                continue;
            }
        }
    }
    return ret;

}
```