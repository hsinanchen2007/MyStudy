### 解题思路
也不知道有没有问题，反正是过了= =
大体思路就是：检测map中是否有重复的值，如果没有get方法会返回NULL
之后存入将该值存入map中

如果不是null，则说明有重复，返回对应的数组值即可

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(map.get(nums[i]) == null){
                map.put(nums[i],i);
            }else{
                return nums[i];
            }
        }
        throw new IllegalArgumentException("不存在重复值");
    }
}
```