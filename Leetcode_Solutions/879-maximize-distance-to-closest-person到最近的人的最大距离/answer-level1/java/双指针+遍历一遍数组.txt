![2020020901.PNG](https://pic.leetcode-cn.com/820cdbee785e8d3161803d40fe48b4c2fad5f74ffc7f529af764bda824921d91-2020020901.PNG)
### 解题思路
//双指针+遍历一遍数组:
//声明右指针right,该指针往前遍历;
//当seats[right]==1时:若seats[left]==0,距离的计算方式为--d=right-left;
//若seats[left]==1,距离的计算公式为--d=(right-left)/2;
//判断d是否大于out,若d大于out,则更新out--out=d;
//同时更新left--left=right;
//当right!=1&&right==seats.length-1时,距离的计算公式--d=right-left;
//若d大于out,则更新out--out=d;
//最后返回out.
### 代码

```java
class Solution {
    public int maxDistToClosest(int[] seats) {
    	int left=0;
    	int right=0;
    	int out=-1;
    	while(right<seats.length) {
    		if(seats[right]==1) {
    			if(seats[left]==0) {
    				if(right>=out) {
    					out = right;
    				}
    			}else if(seats[left]!=0) {
					if((right-left)/2>out) {
						out=(right-left)/2;
					}
				}
   				left=right;
    		}else if(right==seats.length-1&&seats[right]!=1) {
    			if(right-left>out) {
    				out = right-left;
    			}
    		}
    		right++;
    	}
    	return out;
    }
}
```