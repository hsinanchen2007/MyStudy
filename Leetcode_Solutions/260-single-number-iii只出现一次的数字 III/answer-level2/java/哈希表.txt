### 解题思路


### 代码

```java
class Solution {
    public int[] singleNumber(int[] nums) {
        int[] res = new int[2];
        HashMap<Integer, Integer> hashmap = new HashMap<>();

        for(int i = 0; i < nums.length; i++){
            if(!hashmap.containsKey(nums[i]))
                hashmap.put(nums[i], 1);
            else
                hashmap.put(nums[i], hashmap.get(nums[i])+1);
        }

        Set<Integer> keySet = hashmap.keySet();
        int index = 0;
        for(int key : keySet){
            if(hashmap.get(key) == 1){
                res[index] = key;
                index += 1;
            }
        }
        return res;
    }
}
```