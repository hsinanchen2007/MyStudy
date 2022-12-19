### 解题思路
比较异位词，即比较两字符串是否包括个数相同的字母，可先转化为字符组并通过Arrays进行排序，然后再转化为字符串比较值相等



### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()) return false;
        char [] ss = s.toCharArray();
        char [] tt = t.toCharArray();
        Arrays.sort(ss);
        Arrays.sort(tt);
        s = new String(ss);
        t = new String(tt);
        if(s.equals(t))
            return true;
        return false;
        

    }
}
```