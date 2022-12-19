### 解题思路
1. 将字符串hash到一个长度为26的数组中，数组下标对用字母的顺序，数组中的值代表该字母出现的次数
2. 然后再比较hash后的两个数组是否相等

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        return Arrays.equals(toHashArray(s),toHashArray(t));
    }

    private int[] toHashArray(String s){
        int [] sa = new int[26];
        for(char sc : s.toCharArray()){
            sa[sc - 'a'] += 1;
        }
        return sa;
    }
}
```