### 解题思路
此处撰写解题思路
参考答案，还是需要多练习，多努力！！！
时间复杂度：O(log2n)
空间复杂度：O(1)
### 代码

```java
class Solution {
    private int devide(int []nums,int target,boolean left){
        int l=0,r=nums.length;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>target || left && target==nums[mid]){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    public int[] searchRange(int[] nums, int target) {
        int []A={-1,-1};
        int ll=devide(nums,target,true);
        if(ll==nums.length || nums[ll]!=target)
            return A;
        A[0]=ll;
        A[1]=devide(nums,target,false)-1;
        return A;

    }

}
```