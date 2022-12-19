### 解题思路
利用Map这种键值（key-value）映射表的数据结构，能够快速通过key来查找value。

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>(); //创建Map映射表
        for(int i = 0; i< nums.length; i++) { 
            if(map.containsKey(target - nums[i])) {  //boolean containsKey（K key）用来查询某个Key是否存在
                return new int[] {map.get(target-nums[i]),i}; //map.get(K key)用来得到value
            }
            map.put(nums[i], i); //map.put(K key, V value)用来给映射表添加新映射关系
        }
        throw new IllegalArgumentException("No two sum solution"); //抛出异常情况
    }
}

```