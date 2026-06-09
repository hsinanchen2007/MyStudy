### 解题思路
  借用数组来存储字符出现的次数，然后找到第一个值为1的字符

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        if(s == "" || s == null) return ' ';
        int[] arr = new int[26];
        int i,j,k = 1;
        for(i=0;i < s.length();i++){
            arr[s.charAt(i) - 97] ++;
        }
        for(i=0;i<s.length();i++){
            if(arr[s.charAt(i) - 97] == 1){
                return s.charAt(i);
            }
        }
        return ' ';
    }
}
```