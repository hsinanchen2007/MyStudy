### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
    int len=nums.length;
    for(int i=0;i<k;i++){
        int v=nums[i];
        int pos=i;
        for(int j=i+1;j<len;j++){
            if(nums[j]>v){
                v=nums[j];
                pos=j;
            }
        }
        nums[pos]=nums[i];
        nums[i]=v;
    }
    return nums[k-1];   
    }
}
```