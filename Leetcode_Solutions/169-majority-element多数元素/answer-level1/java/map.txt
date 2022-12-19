### 解题思路
使用map 计数 找出出现次数最多的
### 代码

```java
class Solution {
      public static int majorityElement(int[] nums) {
        Map<Integer,Integer> map  = new HashMap<>();
        for (int i  = 0; i < nums.length; i++){
            if(map.containsKey(nums[i])){
                int num = map.get(nums[i]) + 1;
                map.put(nums[i],num);
            } else{
                map.put(nums[i],1);
            }

        }
        int max = 0;
        int maxKey = 0;
        for(Integer key : map.keySet()){
            if(map.get(key) > max) {
                max = map.get(key);
                maxKey = key;
            }
        }
        return maxKey;
    }
}
```