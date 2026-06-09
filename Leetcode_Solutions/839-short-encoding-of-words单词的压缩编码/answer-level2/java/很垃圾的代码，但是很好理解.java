### 解题思路
1.代码虽然很垃圾，留个脚印
2.distinct很重要。

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        int len = words.length;
        if (len == 0) {
            return len;
        }
        if (len == 1) {
            return words[0].length() + 1;
        }
        //去重很重要
        List<String> list = Stream.of(words).distinct().collect(Collectors.toList());
        //记录是别人的尾巴。
        Set<String> set = new HashSet<>();
        int result = 0;
        //双重循环的原因是为了找出a not endsWith(b) 但是 b is endsWith(a);
        for (int j = 0; j < list.size(); j++) {
            for (int i = 0; i < list.size(); i++) {
                if (list.get(j).endsWith(list.get(i)) && i != j) {
                    set.add(list.get(i));
                }
            }
        }
        for (String s : list) {
            if (!set.contains(s)) {
                result = result + s.length() + 1;
            }
        }
        return result;
    }
}
```