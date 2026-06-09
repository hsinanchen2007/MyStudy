### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int l=0;
         for(int r=0;r<nums.length;r++){
             if(nums[r]!=val){
                 swap(nums,l,r);
                 l++;
             }
         }
         return l;
    }
    public void swap(int[] arr,int x,int y){
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
}
```