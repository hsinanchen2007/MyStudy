### 解题思路
此处撰写解题思路
用HashMap的查找key的方法寻找补足的数字, 用key查找value的方法得到数字的标号, 以此判断是否为同一项.
看来hashmap对象的key可以重复
### 代码

```java
class Solution {
    public int[] twoSum(int [] nums, int target){
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            map.put(nums[i],i);
        }

        for(int i=0;i<nums.length;i++){
            int complement = target - nums[i];
            if(map.containsKey(complement)&&map.get(complement)!=i){
                return new int[] {i,map.get(complement)};
            }
            
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
```