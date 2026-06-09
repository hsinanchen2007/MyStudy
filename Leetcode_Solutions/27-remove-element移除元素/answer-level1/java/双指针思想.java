### 解题思路
使用双指针的思想，相当于给数组重新赋值，然后返回赋值的次数即可

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int j=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
}
```