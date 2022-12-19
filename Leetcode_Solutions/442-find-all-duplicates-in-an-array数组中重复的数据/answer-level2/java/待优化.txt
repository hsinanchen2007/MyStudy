### 解题思路


### 代码

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> list = new ArrayList<>();
        HashMap<Integer, Integer> hashmap = new HashMap<>();

        for(int i = 0; i < nums.length; i++){
            if(!hashmap.containsKey(nums[i])){
                hashmap.put(nums[i], 1);
            }
            else{
                hashmap.put(nums[i], hashmap.get(nums[i])+1);
            }
        }

        Set<Integer> set = hashmap.keySet();

        for(int key : set){
            if(hashmap.get(key) == 2)
                list.add(key);
        }
        return list;
    }
}
```