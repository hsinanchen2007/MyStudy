### 解题思路
此处撰写解题思路
可直接使用两个for循环进行暴力破解;
返回所得到的的两个数的下标;
若数组中没有符合条件的元素则抛出异常;
### 代码

```java
class Solution {
    //新人小白
    //本题直接采用暴力破解;
    public int[] twoSum(int[] nums, int target) {
        for(int i=0;i<nums.length;i++){
            for (int j=i+1;j<nums.length;j++){
                if(nums[i]+nums[j]==target){
                    return new int[]{i,j};
                }
            }
        }
      throw new IllegalArgumentException();
    
    }
}
```