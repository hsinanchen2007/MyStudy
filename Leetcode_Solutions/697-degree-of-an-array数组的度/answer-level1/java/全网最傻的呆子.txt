### 解题思路
# **1、这是我第一次写解题思路，也是我第一次在没有看题解的情况下，自己写出来的答案**
# **2、可能写的很一般，如果有朋友看了，觉得有地方可以优化的，希望那位朋友提出来**
# **3、争取给能够让更多初学者朋友看懂，因此写多一点的注释，多帮一帮初学者朋友**

# **就拿这个举例子：[1, 2, 2, 3, 1]**
### 代码

```java
class Solution {
    public int findShortestSubArray(int[] nums) {
        // 如果数组是一个空数组或者数组不空，但是里面没有任何元素，那就返回0
        if(nums == null || nums.length == 0){
            return 0;
        }
        // 1、如果数组就1个元素，数组的度就是1，
        // 2、包含这个度1的数组长度的最小值，这个数组长度本身了，就是这个1，因此返回1
        if(nums.length == 1){
            return 1;
        }
        // map1用来统计数组中每个元素出现的次数
        // 比如题中：1 -> 2 (数组中1出现了2次)
        //          2 -> 2 (数组中2出现了2次)
        //          3 -> 1 (数组中3出现了1次)
        Map<Integer, Integer> map1 = new HashMap<>();


        // map2用来记录数组中元素第一次出现时的位置（索引）
        // 比如题中：1 -> 0 (数组中1第一次出现的位置是0)
        //          2 -> 1 (数组中2第一次出现的位置是1)
        //          3 -> 3 (数组中3第一次出现的位置是3)
        Map<Integer, Integer> map2 = new HashMap<>();


        // map3用来记录数组相同元素，第一次出现与最后一次出现之间的长度
        // 比如题中：元素1第一次出现的位置是0，最后一次出现的位置是4，它们之间的长度 = 5
        //          元素2第一次出现的位置是1，最后一次出现的位置是2，它们之间的长度 = 3
        //          元素3第一次出现的位置是3，最后一次出现的位置是3，它们之间的长度 = 1
        Map<Integer, Integer> map3 = new HashMap<>();


        for(int i = 0; i < nums.length; i++){
            // map1用来统计数组中每个元素出现的次数，key = 数组元素， value = 出现的次数
            map1.put(nums[i], map1.getOrDefault(nums[i],0) + 1);
            // map2用来记录数组中元素第一次出现时的位置（索引），key = 数组元素， value = 第一次出现的位置（索引）
            if(!map2.containsKey(nums[i])){
                map2.put(nums[i],i);
            }
            // map3用来记录数组相同元素，第一次出现与最后一次出现之间的长度，key = 数组元素， value = 第一次出现与最后一次出现之间的长度
            // 数组元素第一次出现的位置保存在map2中，可以从里面拿出来
            map3.put(nums[i],i - map2.get(nums[i]) + 1);
        }
        // maxCount用来记录数组的度
        int maxCount = 0;
        //  map1中存了数组元素的次数，将出现次数的最大值取出来，放到maxCount中
        for(int num : map1.values()){
            maxCount = Math.max(maxCount, num);
        }
        // minLength用来记录最终的答案，保存最短连续子数组的长度，初始化为最大值
        // minLength是用来保存最小值的，将其初始化为最大值，才能不断更新，得到更小的，再更新得到更小的，最终得到的是最小的
        int minLength = Integer.MAX_VALUE;
        for(int key : map1.keySet()){
            // 如果有多个数组元素，它们的度都是maxCount，则选择长度最小的数组元素，
            // 以这个数组元素为key，获取其第一次出现与最后一次出现之间的长度，其长度保存在map3当中
            if(maxCount == map1.get(key)){
                minLength = Math.min(minLength, map3.get(key));
            }
        }
        return minLength;
    }
}
```