### 解题思路
因为是排序的一次遍历 只要找到增量不为1的前后变量即可

### 代码

```java
public class Solution {
		  public int missingNumber(int[] nums) {
			  int n=0;
			  int d = 1;//增量
	          int i=0;
			  for(;i<nums.length-1;i++) {
				  d=nums[i+1]-nums[i];
				  if(d>1) {
					  n = nums[i]+1;
                      break;
				  }
			  }
			  if(d==1&&nums[0]!=0) {
				  n=0;
			  }
			  if(d==1&&nums[0]==0) {
				  n=nums[nums.length-1]+1;
			  }
			  
			  return n;
		    }
	}

```