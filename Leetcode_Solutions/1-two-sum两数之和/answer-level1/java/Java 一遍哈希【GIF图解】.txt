## 解题思路
**题目要求：** 在数组中找到两个元素的索引，且这两个元素相加等于目标值。
**思路：**
在数组中找出两个元素。我们第一时间就可以想到使用两层循环进行查找，外循环寻找第一个元素，内循环寻找第二个元素。
但是，这种方法的效率非常低。在这一道题中，我们主要的任务是 **找** ，也就是遍历。
所以我们需要一种比较快速的遍历方法，那就是 `map.containsKey()` 方法。

我们用 `map.containsKey()` 方法代替内循环的查找工作。
1. for循环遍历每一个元素，在map中查找与该元素符合条件的元素。
2. 如果map中没有符合条件的元素，则将该元素放入map中。
3. 为下一个元素寻找符合条件的元素。

**一遍哈希遍历代码:**
```java
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    int length = nums.length;
        
    for(int i = 0; i < length; i++){
        int value = target - nums[i];
        // 如果 map 存在此差值，则返回
        if(map.containsKey(value)){
            return new int[]{i, map.get(value)};
        }
        // 将该数组的值存入 map
        map.put(nums[i], i);
    }
    return null;
}
```
![两数之和.gif](https://pic.leetcode-cn.com/5c31c1ec3942f46c3bf545653e413c42ef64a697b733c97a4fee8fe946447f46-%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.gif)


博客：www.lxiaocode.com