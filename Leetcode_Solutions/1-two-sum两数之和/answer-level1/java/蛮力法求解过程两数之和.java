从头开始遍历数组，将每个数分别与与数组其他数匹配。不顾此种方法过于费时，因为每次遍历都是将一个数与全部元素匹配，复杂度最高
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] a = new int[2];
        for(int i = 0;i<nums.length;i++){
            for(int j = i+1;j<nums.length;j++){
                if(target == nums[i]+nums[j]){
                  a[0] = i;
                  a[1] = j;
                  return a;
                }
            }
        }
        return a;
    }
}
```