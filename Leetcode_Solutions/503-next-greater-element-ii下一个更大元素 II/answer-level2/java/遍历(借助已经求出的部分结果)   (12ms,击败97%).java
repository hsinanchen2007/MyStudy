  第一次做这道题目的时候，采用的暴力循环的方式
```
class Solution {
    public int[] nextGreaterElements(int[] nums) {
 		int length= nums.length;
 		int[] result= new int[length];
 		for(int i=0;i<length;i++){
 			int j=i+1;
 			for (;j%length!=i;j++ ) {
 				if(nums[j%length]>nums[i]){
 					result[i]=nums[j%length];
 					break;
 				}
 			}
 			if(j%length==i)
 				result[i]=-1;
 		}
 		return result;       
    }
}
```
  运行时间是300ms,只击败了5%，速度是非常慢的。后来想到这类题目一般都可以根据result数组中已经求出来的部分值进行优化。于是我的优化思路如下:
![图片.png](https://pic.leetcode-cn.com/5b99d38580b6e3057b44fb75294e1f882cfdc977740b1a10c301305faf0ac1ab-%E5%9B%BE%E7%89%87.png)
  从后向前算，求出最后一位nums[n]对应的result[n],
  对于倒数第二位nums[n-1],先比较nums[n-1]与nums[n]的大小，
  		如果nums[n-1]<nums[n],result[n-1]的值就是nums[n]；
  		如果nums[n-1]>=nums[n],此时再比较nums[n-1]与result[n]大小
--------------**如果nums[n-1]<result[n],result[n-1]的值就是result[n]**
--------------如果nums[n-1]>=result[n],那就只好从首位开始遍历求出最大的值了。
  
因此对于nums数组中间的n-i位,会不断与身后的j位元素(j=n-i+1,n-i+2.....n)比较nums[n-i]和nums[j]大小以及nums[n-i]与result[j]的大小，从而求出result[n-j]的值。如果把身后的值都遍历完了，只好从首位开始遍历求出最大值。
代码如下
```
class Solution {
    public int[] nextGreaterElements(int[] nums) {
 		int length= nums.length;
 		int[] result= new int[length];
 		for(int i=length-1;i>=0;i--){
 			int j=i+1;
 			for(;j<length;j++){
 				if(nums[j]>nums[i]){
 					result[i]=nums[j];
 					break;
 				}
 				else{
 					if(nums[i]<result[j]){
 						result[i]=result[j];
 						break;
 					}
 				}
 			}
 			if(j==length){
 				for(j=0;j<i;j++){
 					if(nums[j]>nums[i]){
 						result[i]=nums[j];
 						break;
 					}
 				}
 				if(j==i)
 					result[i]=-1;
 			}
 		} 
 		return result;   
    }
}
```
运行速度是12ms，击败了97%，优化的结果我是比较满意的，但是代码的长度且整洁度不是很满意。