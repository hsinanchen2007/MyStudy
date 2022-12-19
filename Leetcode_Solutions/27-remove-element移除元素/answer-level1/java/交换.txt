### 解题思路
该方法复杂度较高

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int i,j,k=0;
        //找出数组中val的值个数
        for(i=0;i<nums.length;i++){
            if(nums[i]==val){k++;}}
        //将数组中val的值与非val值互换
        for(i=0;i<nums.length;i++){
            if(nums[i]==val){
                for(j=i+1;j<nums.length;j++){
                    if(nums[j]!=val){
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        break;
                    }
                }
                
            }
        }
        return nums.length - k;
    }
}
```