### 解题思路
![QQ截图20200302152109.png](https://pic.leetcode-cn.com/0998b319f336c61161f8ec44fc8d7929118387a5d0df2ef8cc37cd9972e57c22-QQ%E6%88%AA%E5%9B%BE20200302152109.png)

使用标记数组flag[]统计各字符出现次数，若为偶数则全部计入回文串长度sum（两端对称正好用完），若为奇数则减一后计入。最后若sum与原串长度一样则直接返回（所有字符都能用上）若不然则加一返回（取奇数个字符中一个放在最中间）


### 代码

```c
#define SIZE 100
int longestPalindrome(char * s){
    int slen=strlen(s);
    int i,sum;
    int flag[SIZE]={0};
    for(i=0;i<slen;i++){
        flag[s[i]-'A']++;
    }
    sum=0;
    for(i=0;i<SIZE;i++){
        if(flag[i]%2==0){
            sum+=flag[i];
        }else{
            sum+=flag[i]-1;
        }
    }
    if(sum==slen){
        return sum;
    }else{
        return sum+1;
    }

}
```