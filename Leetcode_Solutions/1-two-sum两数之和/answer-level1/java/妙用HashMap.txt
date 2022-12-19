### 解题思路
本题不仅要找出两个数，还得要找出这两个数的索引。
从数据角度看，一个数值和它的索引构成一个对象，这就是典型的 键值对，因此可以考虑用Map可以存储该数据结构。
同时利用Map的contains方法获取值和索引

二次循环算法简单暴力，但是没有HashMap来的高效。 

### 代码

```java
// solution 1
// class Solution {
//     public int[] twoSum(int[] nums, int target) {
//         // int[] result = new int[2];
//         for(int i = 0; i < nums.length ; i++) {
//             for(int j = i+1; j < nums.length; j++){
//                 if((target - nums[i]) == nums[j]){
//                     return new int[]{i, j};
//                 }
//             }
//         }
//         return new int[]{-1, -1};
//     }
// }

// solution 2
// 方案2中， 循环了两次，能否只做到循环一次？
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> myMap = new HashMap<Integer, Integer>();
        // for(int i = 0; i < nums.length; i++) {
        //     myMap.put(nums[i], i);
        // }
        for(int i = 0; i < nums.length; i++){
            int k = target - nums[i];
            if(myMap.containsKey(k) && myMap.get(k) != i) {
                return new int[] {myMap.get(k), i};
            }
            myMap.put(nums[i], i);
        }
        return new int[] {-1, -1};
    }
}
```