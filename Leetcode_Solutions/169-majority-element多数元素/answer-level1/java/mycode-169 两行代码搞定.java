### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
    //方法一
        Arrays.sort(nums);
        return nums[nums.length / 2];
    //方法二
//        HashMap<Integer, Integer> map = new HashMap<>();
//        for(int i = 0; i < nums.length; i++){
//            if(map.containsKey(nums[i])){
//                if((map.get(nums[i]) + 1) > (nums.length / 2)) return nums[i];
//                map.put(nums[i],map.get(nums[i]) + 1);
//            }else {
//                map.put(nums[i], 1);
//            }
//        }
//        return nums[0];
    }
}
```