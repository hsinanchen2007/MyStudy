### 解题思路
思路：
如果数组中元素存在，则出现次数加1
如果数组元素不存在，则将出现次数置为1

最后遍历keySet表，然后找到value值为1的。

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> hashmap = new HashMap<>();

        for(int i = 0; i < nums.length; i++){
            if(!hashmap.containsKey(nums[i]))
                hashmap.put(nums[i], 1);
            else
                hashmap.put(nums[i], hashmap.get(nums[i])+1);
        }

        int res = 0;
        Set<Integer> set = hashmap.keySet();
        for(int key : set){
            if(hashmap.get(key) == 1){
                res = key;
                break;
            }
        }
        return res;
    }
}
```