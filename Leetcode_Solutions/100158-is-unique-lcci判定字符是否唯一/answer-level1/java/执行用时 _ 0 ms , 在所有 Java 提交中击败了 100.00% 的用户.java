### 解题思路
1.将字符串转成char数组
2.定一个Set集合，用于存储char数组的每一个char
3.判断字符串的len和set几个的size是否一致

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        if(astr == null || astr == ""){
            return true;
        }
        int len = astr.length();
        char[] ch = astr.toCharArray();
        Set<Character> set = new HashSet<>();
        for(char c : ch){
            set.add(c);
        }

        return len == set.size();
    }
}
```