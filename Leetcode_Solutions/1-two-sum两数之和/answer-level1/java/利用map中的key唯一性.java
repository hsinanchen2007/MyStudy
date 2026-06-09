
利用Map中key的唯一性，假设 target = x + y，那么如果求y的值，也就是 y = target - x，将target - x 的值作为key，x的下标作为value,循环nums找到y的值，那么就得到俩数之和下标。



```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        //  target = x + y ;
        //  y = target - x;
        int [] result = new int [2];
        Map<Integer,Integer> tempIndexMap = new HashMap();
        for ( int i = 0; i < nums.length ; i++ ){
            //  target - nums[i] = y
            if ( tempIndexMap.containsKey(nums[i]) ){
                result[0] = tempIndexMap.get(nums[i]);
                result[1] = i;
                break;
            }
            tempIndexMap.put( target - nums[i] ,i);
        }
        return result;

    }
}
```