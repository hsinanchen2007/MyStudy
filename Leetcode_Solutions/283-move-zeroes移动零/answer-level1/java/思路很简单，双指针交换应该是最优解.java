### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int[] newArr = new int[n];
        
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
				newArr[j] = nums[i];
                j++;
            }
        }
        System.arraycopy(newArr,0,nums,0,n);
    }
}
```