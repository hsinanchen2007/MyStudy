### 解题思路
![捕获2.PNG](https://pic.leetcode-cn.com/a5d269dd66716713bb583f940371c22c0f574cfe0c274b5e991cbd77a0455de9-%E6%8D%95%E8%8E%B72.PNG)


### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        int len=s.length();
        String ans="";
        char[] c=s.toCharArray();
        for(int i=0;i<len;i++){
            if(c[i]==' '){
                ans+="%20";
            }else{
                ans+=c[i];
            }
        }
        return ans;
    }
}
```