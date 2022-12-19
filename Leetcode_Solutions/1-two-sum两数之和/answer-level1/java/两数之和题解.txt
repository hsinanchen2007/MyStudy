# 写在前面：
- 整体思路分析：
    如果给定序列是有序的，那就很好解决，常规思路也很容易保证时间复杂度时间复杂度位O(n)，但在无序的情况下呢？首先可以考虑先排序，但这样的思路时间复杂度依旧很难做到比较理想，如果使用哈希表，就可以保证一次遍历得到答案，是复杂度最坏情况也能是O(n)，具体看代码分析

# 代码分析：
```
public static int[] twoSum(int[] nums,int target) {
    HashMap<Integer,Integer> map = new HashMap<>();
    for(int i = 0;i< nums.length;i++) {
        int res = target - nums[i];//每一轮循环要寻找的目标元素
        if(map.containsKey(res)) {//若目标元素存在，则直接返回当前元素和目标元素的下标构成的数组
            return new int[] {map.get(res),i};
        }
        map.put(nums[i], i);//若不存在，则将当前元素及其下标加入到map中，给之后的循环继续比对
    }
    return new int[0];//若遍历整个数组也找不到这样的两个数，则返回一个空数组
}
```
