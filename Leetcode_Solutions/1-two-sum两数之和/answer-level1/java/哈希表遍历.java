### 解题思路
一遍哈希标做法，将数组索引为key值，数组元素为value值，在将元素放入哈希标的同时进行判断，根据题意，目标元素不能是重复索引
我们只需要判断target - nums[i]对应的value值是否能在集合中找到key值，并且这个key值不能是i本身，然后保存找到的索引。
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
//key值为索引，value值为数组的每个元素
     Map <Integer , Integer> map = new HashMap<>();
//将数组的各个元素依次放入到哈希表中
     for (int i = 0 ; i < nums.length ; i++){
        int index = target - nums[i];
//当哈希表包含 index对应的key值并且对应的key值不是本身进入判断
        if (map.containKey(index) && map.get(index) != i){
             //将找到的key值保存下来
             return int [] {i,map.get(index)};
        }
        map.put(i,nums[i]);
       
      }

    }
}
```