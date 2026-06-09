### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer , Integer> map = new HashMap();
            int size = nums.length;
            int[] index = new int[2];
            for(int i = 0 ; i < size ; i ++){
                if(map.containsKey(nums[i])){
                    index[0] = map.get(nums[i]);
                    index[1] = i;
                    break;
                }else{
                    int temp = target - nums[i];
                    map.put(temp , i);
                }
            }
            return index;
    }
}
```
把余数作为key传到map里面去，如果下一个值有和余数一样的则可以直接 根据这个余数对应的下角标取出来