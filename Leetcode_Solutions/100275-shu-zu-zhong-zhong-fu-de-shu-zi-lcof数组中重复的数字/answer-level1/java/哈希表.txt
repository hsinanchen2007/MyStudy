### 解题思路
依次将数组中的元素放入哈希表中。放入的时候执行一个判断，如果存在key，那么表示已经存在重复的元素了，就直接return nums[i];如果都成功加入，那么就不存在重复元素，跳出循环，返回-1。

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        HashMap<Integer, Integer> hashmap = new HashMap<>();

        for(int i = 0; i < nums.length; i++){
            if(!hashmap.containsKey(nums[i])){
                hashmap.put(nums[i], 1);
            }else{
                //表示已经存在了
                return nums[i];
            }
        }
        //不存在重复的元素
        return -1;
    }
}
```