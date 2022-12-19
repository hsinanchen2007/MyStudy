### 解题思路
此处撰写解题思路
可以利用Java8的特性，使用lamba表达式；利用compareTo，其中compareTo的比较，如果有数组[3,34,300]，先比较34300和30034发现后一个更小，因此将300放在34前面，同理和3比较最后数组中数字的顺序变为300334
### 代码

```java
class Solution {
    public String minNumber(int[] nums) {
        List<String> strList = new ArrayList<>();
        for (int num : nums) {
            strList.add(String.valueOf(num));
        }
        strList.sort((s1, s2) -> (s1 + s2).compareTo(s2 + s1));
        StringBuilder sb = new StringBuilder();
        for (String str : strList) {
            sb.append(str);
        }
        return sb.toString();
    }
}
```