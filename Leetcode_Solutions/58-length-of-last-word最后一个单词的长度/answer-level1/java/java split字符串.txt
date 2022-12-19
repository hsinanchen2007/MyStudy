### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        if(s == null || s.trim().length()==0)
            return 0;
        String[] arr = s.trim().split(" ");
        return arr[arr.length-1].length();
    }
}
```