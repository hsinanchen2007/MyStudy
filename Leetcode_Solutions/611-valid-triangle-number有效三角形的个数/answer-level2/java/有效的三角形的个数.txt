### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int triangleNumber(int[] nums) {
    Arrays.sort(nums);
    int count=0,k=0,j=0;
    for(int i=2;i<nums.length;i++){
      k=0;j=i-1;
      while(k<j){
          if(nums[k]+nums[j]>nums[i]){
              count+=j-k;
              j--;
          }
          else{
              k++;
          }
          
      }
    }
    return count;
    }
}
```