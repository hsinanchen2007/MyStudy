分析: 通过排序将组合理论上较大的数字放在前面, 之后结合即可;

注意:

    1. 使用比较时使用了自定义比较: (y + x).compareTo(x + y);
    2. 解法中使用stream, 先将int转为了String数组, 然后, 排序, 最后遍历加入结果;

由于使用了LambdaL和Stream表达式, 代码显得很简洁.

```java
class Solution {

    private StringBuilder res;

    public String largestNumber(int[] nums) {
        res = new StringBuilder();
        Arrays.stream(nums).boxed().map(x -> x.toString()).sorted((x, y) -> (y + x).compareTo(x + y)).forEach(x -> res.append(x));
        return res.charAt(0) == '0' ? "0" : res.toString();
    }
}
```

