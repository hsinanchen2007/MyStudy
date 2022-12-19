### 解题思路
![image.png](https://pic.leetcode-cn.com/27cf37fccb673069b14541d28b4fef6507153167eab4f52de248fe50509b0767-image.png)
我的思路简单来说，就是“一个中心，两个基本点”

一个中心是指回文子串的对称中心，两个基本点是指回文子串的起点和终点

首先是找中心，我分了两种情况：
一是连续相等的情况，就直接找到连续相等子串的中心，作为对称中心；
二是不相等的情况，就找到一对离得最近的相同字符，作为对称中心。

然后是找两个基本点，就直接从中心开花，向两边遍历，就能找到回文子串起点和终点。

每找到一个子串记录一次子串长度，如果大于最大值，就更新起点和终点，否则不变。


### 代码

```c
char * longestPalindrome(char * s){
    int i,j,single,start=0,end=0,len,longest=1;
    if(strlen(s)==0||strlen(s)==1) return s;
    for(i=0;s[i+2]!='\0';i++){
        if(s[i]==s[i+1]||s[i]==s[i+2]){
            if(s[i]==s[i+1]&&s[i]==s[i+2]){
                for(j=3;s[i+j]==s[i];j++);
                single=j%2==1?1:0;
                i=i+j/2-1;
            }else single=s[i]==s[i+2]?1:0;
            for(j=0;i-j>=0&&s[i+j+single+1]!='\0';j++){
                if(s[i-j]!=s[i+j+single+1]) break;
            }
            len=2*j+single;
            if(len>longest){
                longest=len;
                start=i-j+1;
                end=i+j+single;
            }
        }
    }
    if(s[i]==s[i+1]&&longest==1){
        start=i;
        end=i+1;
    }
    s[end+1]='\0';
    return s+start;
}
```