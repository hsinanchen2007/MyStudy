### 解题思路
其实就是求next数组
next数组的意思就是比如第i个位置next[i]表示0到i-1之间，0到k, i-k-1到i-1(前缀和后缀是一样长度)两个串是一样的
比如:
next[i]     -1  0   0   1   2   3   4 
字符串       a   b   a   b   a   b
### 代码

```java
class Solution {
    public String longestPrefix(String s) {
        if(s.length()<=1) return "";
        int[] next=getNext(s);
        return s.substring(0,next[s.length()]);
    }
    int[] getNext(String s){
        int[] next=new int[s.length()+1];
        next[0]=-1;next[1]=0;   // 初始化
        int pos=2,len=0;
        while(pos<s.length()+1){
            if(s.charAt(pos-1)==s.charAt(len)){
                next[pos++]=++len;
            }else if(len>0){
                len=next[len];  // 不匹配，切当前长度不等于0，那么就寻找当前位置的前缀，开始匹配，是一个加速的过程
            }else{
                next[pos++]=0;
            }
        }
        return next;
    }
}
```