# 步骤
先用Stream生成由1-n组成的List
再对List排序即可

# 代码
```java
class Solution {
    public List<Integer> lexicalOrder(int n) {
        // List<Integer> res = Stream.iterate(1, item -> item + 1).limit(n).collect(Collectors.toList());
        // Collections.sort(res, Comparator.comparing(String::valueOf));
        // return res;
        return Stream.iterate(1, item -> item + 1).limit(n).sorted(Comparator.comparing(String::valueOf)).collect(Collectors.toList());
    }
}
```
