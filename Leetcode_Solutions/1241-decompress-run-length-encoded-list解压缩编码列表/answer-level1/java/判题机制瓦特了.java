看到别人Java 2ms，我这代码50ms却也提示超过100%，一言难尽。
看到这题目的描述，emmm，又想起来赛场上被题目描述虐的场景，算法题的描述绝对是我做过最难的阅读理解，这特么更是一言难尽。

``` java
class Solution {
    public int[] decompressRLElist(int[] nums) {

        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i += 2)
            for (int j = 0; j < nums[i]; j++)
                list.add(nums[i + 1]);

        return list.stream().mapToInt(Integer::valueOf).toArray();
    }
}
```
