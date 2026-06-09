### 解题思路
此处撰写解题思路
依次在t字符串中查找s字符串中出现的字符，java中有一个indexOf()方法，可以快速在字符串中查找是否存在要查找的字符，第二个参数表示从下标为pos的字符开始查找，每次出了i++以外,pos也要++,因为可能存在连续的相同字符，如果pos不自行+1的话，会在t字符串中一直重复查找那个字符，产生错误。
### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        for(int i=0,pos=0;i<s.length();i++,pos++){
             pos=t.indexOf(s.charAt(i),pos);
             if(pos==-1)
             return false;
        }
        return true;
    }
}
```