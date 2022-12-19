### 解题思路
此处撰写解题思路
见代码
### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {

        if (s==null || s.length()==0) return true;
        int len =s.length();

        Stream<List<String>> stream = Stream.of(s).map(arg -> arg.split(""))
                .flatMap(Arrays::stream)
                .collect(Collectors.groupingBy(arg -> arg)).values().stream();

        // 偶数话，统计每个字符串出现的次数，都为偶数才是回文串
        if ((len & 1) == 0)
            return stream.noneMatch(arg->(arg.size()&1)==1);
        else // 奇数的话，只能有一个字符串是奇数，其他都要是偶数
            return stream.filter(arg->(arg.size()&1)==1).count()==1;

    }
}
```