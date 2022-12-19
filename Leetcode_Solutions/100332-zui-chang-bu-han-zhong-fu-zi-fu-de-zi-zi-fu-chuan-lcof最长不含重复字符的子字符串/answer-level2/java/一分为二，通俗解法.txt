### 解题思路
    直接遍历字符串数组，每次遇到出现过的的字符就将数组以该字符的下标为基准进行分割，此时的max = Math.max(左半边的字符串，有半边的字符串))
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.isEmpty()){
            return 0;
        }
        char[] chars = s.toCharArray();
        int length = chars.length;
        int max = 1;
        String preStr = chars[0] + "";
        for(int i=1;i < length;i++){
            int index = preStr.indexOf(chars[i] + "");
            if(index != -1){
                String rs =  s.substring(index + 1);
                return Math.max(max,lengthOfLongestSubstring(rs));
            }else{
                max = max + 1;
                preStr = preStr + chars[i];
            }
        }
        return max;


    }
}
```