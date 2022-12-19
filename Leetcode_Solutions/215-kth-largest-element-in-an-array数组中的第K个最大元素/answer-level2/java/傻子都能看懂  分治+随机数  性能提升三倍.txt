让left与随机位置交换一下，避免最坏的情况，性能明显提升
![image.png](https://pic.leetcode-cn.com/c771bbaecd7257204072058b5ce02e3eefa6103f9741a519398422ccb5331932-image.png)

```
class Solution {
    public int findKthLargest(int[] nums, int k) {
        
        k=nums.length-k;
        if(k<0)return -1;
        int left=0,right=nums.length-1;
        while(left<=right){
            int i=partition(nums,left,right);
            if(k==i)return nums[k];
            else if(k>i) left=i+1;
            else right=i-1;
        }
        return -1;
    }

    public int partition(int[] nums,int l,int r){
        if(l==r)return l;
        Random rand = new Random();
        int x=rand.nextInt(r-l)+l;
        swap(nums,l,x);
        int temp=nums[l];
         
        while(l<r){
            while(l<r&&nums[r]>=temp)r--;
            if(l<r)swap(nums,l,r);
            while(l<r&&nums[l]<=temp)l++;
            if(l<r)swap(nums,r,l);
        }
        nums[l]=temp;
        return l;
         
      
    }

    public void swap(int[] nums,int a,int b){
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
}
```
