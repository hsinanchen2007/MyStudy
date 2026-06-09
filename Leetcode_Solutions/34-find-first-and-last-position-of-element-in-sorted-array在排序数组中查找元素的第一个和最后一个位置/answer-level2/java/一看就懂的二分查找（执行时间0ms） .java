左边界是什么，就是当前下标i对应的nums[i]==target且nums[i-1]!=target(或当前下标i为0)
右边界是什么，就是当前下标i对应的nums[i]==target且nums[i+1]!=target(或当前下标i为nums.length-1)
返回数组初始就赋值[-1,-1]
没有找到边界就不会改变返回数组的值，即返回[-1,-1]
```
class Solution {
    int[] res=new int[2];
    int[] n;
    public int[] searchRange(int[] nums, int target) {
    	n=nums;
    	res[0]=-1;
    	res[1]=-1;
    	devideToTwo(0,nums.length-1,target);
        return res;
    }
    public void devideToTwo(int start, int end, int target) {
    	if(start>end) {return;}
    	int mid=(start+end)/2;
    	if(n[mid]<target) {
    		devideToTwo(mid+1,end,target);
    	}
    	if(n[mid]>target) {
    		devideToTwo(start,mid-1,target);
    	}
        if(n[mid]==target) {
        	if(mid==0||n[mid-1]!=target) {res[0]=mid;}
            else {devideToTwo(start,mid-1,target);}
        	if(mid==n.length-1||n[mid+1]!=target) {res[1]=mid;}
            else {devideToTwo(mid+1,end,target);}
        }
    }
}
```
