### 解题思路
**题目要求：** 判断数组在指定范围内是否有两个相同的元素。
**思路：**
`217 存在重复元素I` 和 `219 存在重复元素II` 的思路几乎是一摸一样，只不过是多了一个需要判断的条件罢了。
（可以去看看我217题的题解）
1. for循环遍历每一个元素，在map中查找与该元素符合条件的元素。
2. 如果map中没有符合条件的元素，则将该元素放入map中。
3. 为下一个元素寻找符合条件的元素。

（刷完题后，把类似的题放到一起就会发现很多思路都是一样的，这时候就会学会举一反三了。）
![存在重复元素II.gif](https://pic.leetcode-cn.com/5224d053711afdd6db6e9fd3c5085e42d2d146c06c89efee6d44fa08cdd5f811-%E5%AD%98%E5%9C%A8%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0II.gif)

**哈希遍历代码:**

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int length = nums.length;

        for (int i = 0; i < length; i++){
            // 只比 217 题多了 i - map.get(nums[i]) <= k 的判断
            if (map.containsKey(nums[i]) && i - map.get(nums[i]) <= k){
                return true;
            }
            map.put(nums[i], i);
        }
        return false;
    }
}
```
博客：www.lxiaocode.com