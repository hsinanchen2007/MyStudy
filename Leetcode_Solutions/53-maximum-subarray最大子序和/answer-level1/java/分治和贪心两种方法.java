### 解题思路
注意分治的划分方法和合并方法

### 代码

```java
class Solution {//简单的分治算法:1.划分2.递归3.合并
	public int maxSubArray(int[] nums) {
        // return fenzhi_helper(nums,0,nums.length);
        return tanxin_helper(nums);
    }
    public int fenzhi_helper(int[] nums,int left,int right){
        if(left-right==-1) return nums[left];
        //分治第一步:划分
        int mid=left+(right-left)/2;
        //分治第二步:递归
        int max=Math.max(fenzhi_helper(nums,left,mid),fenzhi_helper(nums,mid,right));
        //分治第三步:合并(左闭右开)
        int L=nums[mid-1];
        int R=nums[mid];
        int curr=0;
        for(int i=mid-1;i>=left;i--) L=Math.max(L,curr+=nums[i]);
        curr=0;
        for(int i=mid;i<right;i++) R=Math.max(R,curr+=nums[i]);
        return Math.max(max,L+R);
    }
    public int tanxin_helper(int[] nums){
        int maxSum=nums[0];
        int nowMax=nums[0];
        for(int i = 1;i<nums.length;i++){// 从第2个元素开始比较
            maxSum=Math.max(nums[i]+maxSum,nums[i]);
            nowMax=Math.max(maxSum,nowMax);
        }
        return nowMax;
    }
}
```