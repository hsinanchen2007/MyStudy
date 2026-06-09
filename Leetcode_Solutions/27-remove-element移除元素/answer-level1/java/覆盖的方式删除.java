### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int count=nums.length;
        for(int i=0;i<count;i++){
            if(nums[i]==val){
              for(int j=i;j<nums.length-1;j++){   //覆盖
                  nums[j]=nums[j+1];
              }
               i--; 
               count--;
            }
        }
        return count;

    }
}
```