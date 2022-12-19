### 解题思路
暴力for

### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
   int len=nums.length-1;
		int i,j,k,lengthnow;
		int minlength=Math.abs(target-(nums[0]+nums[1]+nums[2]));
        //length的初值是前三个数对应的差值
		int result=nums[0]+nums[1]+nums[2];
		for(i=0;i<=len-2;i++) {
			for(j=i+1;j<=len-1;j++) {
				for(k=j+1;k<=len;k++) {
					lengthnow=Math.abs(target-(nums[i]+nums[j]+nums[k]));//lengthnow是当前差值
					minlength=Math.min(lengthnow,minlength); 
                    //length是之前length和现在length之间较小值
					result=(lengthnow==minlength)?(nums[i]+nums[j]+nums[k]):result;
				   }
		      }
        }
		return result;
    }
}
```