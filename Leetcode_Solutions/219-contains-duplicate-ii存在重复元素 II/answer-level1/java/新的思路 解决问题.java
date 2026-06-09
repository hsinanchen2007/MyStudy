### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<nums.length;i++){
           if(map.containsKey(nums[i])){
               Integer j=map.get(nums[i]);
               if(i-j<=k) return true;
           }
           /***
             如果map里面已经含有该元素,则更新该元素新的索引,
             更新操作主要是如果某个元素出现二次以上时候,则
             更新最近一次出现一次的索引,寻找是否满足条件
             如果map里面没有该元素,则添加
            ***/
           map.put(nums[i],i);
        }
        return false;
    }
}
```