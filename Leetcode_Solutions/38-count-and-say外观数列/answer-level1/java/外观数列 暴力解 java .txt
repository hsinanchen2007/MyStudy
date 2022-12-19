![image.png](https://pic.leetcode-cn.com/14ab6afdf05de30b7b4758191ee0c70f623c9067170e17c9574e8eb620ae7b87-image.png)

### 解题思路
按照题目的意思就是数列n+1对n进行报数
1       1个1
11      2个1
21      1个2 1个1
1211    1个1 1个2 2个1
111221  ...依次类推
按照这个思路，我的想法是第[1+2i]位数通过count计数,[2+2i]为通过charAt(j)获取的上一数列表示的数值
n--得到是第n列
比较麻烦，暴力解法

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String s="1",s2="1";
        int count=1;
        char t='0';
        while(n!=1){
            s=s2;
            s2="";
            count=1;
            t=s.charAt(0);//第一个字符
            for(int j=1;j<s.length();j++){
                if(t!=s.charAt(j)){
                    s2=s2+String.valueOf(count)+t;
                    t=s.charAt(j);
                    count=1;
                }else{
                    count++;
                }
            }
            s2=s2+String.valueOf(count)+t;
            n--;
        }
        return s2;
    }
}
```