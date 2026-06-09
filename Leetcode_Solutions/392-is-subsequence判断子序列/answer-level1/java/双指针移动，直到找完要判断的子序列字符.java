![l.png](https://pic.leetcode-cn.com/7c4dadb38630058b49088ecbb3201ea482fbdc07f7a58ec55a7d12a3f92078a2-l.png)


### 解题思路
大字符串、小字符串两个索引指针从0开始，匹配一个小字符串的字符小字符串索引向前移动一次，大字符索引每次都往前移动一次

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s==null||t==null){
            return false;
        }
        if(s.length()==0){
            return true;
        }
        int si=0,ti=0;
        while(si<s.length()&&ti<t.length()){
            if(s.charAt(si)==t.charAt(ti)){
               si++; 
            }
            ti++;
        }
        return si==s.length();
    }
}
```