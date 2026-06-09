### 解题思路
思路和前一题一样。不过为啥我用了哈希表，内存消耗打败了95%，可时间消耗却只击败了16%，我也只是线性时间啊。

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> hashmap = new HashMap<>();

        for(int i = 0; i < nums.length; i++){
            if(!hashmap.containsKey(nums[i])){
                hashmap.put(nums[i], 1);
            }
            else{
                hashmap.put(nums[i], hashmap.get(nums[i])+1);
            }
        }

        Set<Integer> keyset = hashmap.keySet();
        for(int key : keyset){
            if(hashmap.get(key) == 1){
                return key;
            }
        }
        return 0;
    }
}
```