### 解题思路
此处撰写解题思路
定义两个变量preLen和curLen，分别表示前面连续字符串中字符的个数，现在连续字符串中字符的个数。
当前字符和上一个字符相等时curLen++,不相等时preLen=curLen,然后curLen设为1。
如果preLen>=curLen,那么结果+1。
例如0011,应该输出为2。
1.curLen=1,preLen=0,ret=0;
2.curLen=2,preLen=0,ret=0;
3.curLen=1,preLen=2,ret=1;//001中的01
4.curLen=2,preLen=2,ret=2;//0011中的0011
### 代码

```java
class Solution {
    public int countBinarySubstrings(String s) {
        int preLen=0,curLen=1,ret=0;
        for(int i=1;i<s.length();i++){
            if(s.charAt(i-1)==s.charAt(i)) curLen++;
            else{
                preLen=curLen;
                curLen=1;
            }
            if(preLen>=curLen) ret++;
        }
        return ret;
    }
}
```