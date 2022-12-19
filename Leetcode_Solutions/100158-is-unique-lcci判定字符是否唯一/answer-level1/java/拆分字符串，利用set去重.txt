### 解题思路
可以考虑拆分字符串,生成字符数组,然后使用set方式去重,然后比较元素个数

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        char[] chars = astr.toCharArray();
        int length = chars.length;
        Set<String> set =new HashSet<>();
        for (char c : chars) {
            set.add(String.valueOf(c));
        }
        return length == set.size();
    }
}
```