### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public boolean CheckPermutation(String s1, String s2) {
       if(s1.length() != s2.length()) return false;
        //这里将一个字符传转换成为字符数组
        char[] s1char = s1.toCharArray();
        char[] s2char = s2.toCharArray();
        //使用数组的接口进行排序，然后逐个比对
        Arrays.sort(s1char);
        Arrays.sort(s2char);
        for (int i = 0; i < s1.length(); i++) {
            if(s1char[i] != s2char[i]) return false;
        }
        return true;
    }
}
```