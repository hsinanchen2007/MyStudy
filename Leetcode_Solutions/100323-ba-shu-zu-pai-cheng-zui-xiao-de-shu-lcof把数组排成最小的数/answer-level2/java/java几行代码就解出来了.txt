    **这道题可以先将int数组转换成String类型的list或者数组，然后其实就是比较两个字符串组合之后的孰大孰小，即(str1+str2).compare(str2+str1)的结果，代码如下：**
```
class Solution {
    public String minNumber(int[] nums) {
        List<String> list = Arrays.stream(nums)
                .mapToObj(num->String.valueOf(num))
                .sorted((o1,o2)->(o1+o2).compareTo(o2+o1))
                .collect(Collectors.toList());
        return list.stream().collect(Collectors.joining());
    }
}
```
