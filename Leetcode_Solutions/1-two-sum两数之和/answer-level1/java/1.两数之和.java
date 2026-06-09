### 解题思路
此处撰写解题思路
我用了两个循环，A循环从索引小到大循环，B循环从大到小且B循环的索引必须大于A循环的索引，
这样就可以让每一个元素依次加上其后面的元素。
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for(int i =0;i<nums.length;i++){
            for(int j=nums.length-1;j>i;j--){
                if(nums[i]+nums[j]==target){
                    return new int[]{i,j};
                }
            }
        }
        return null;
    }
}
```