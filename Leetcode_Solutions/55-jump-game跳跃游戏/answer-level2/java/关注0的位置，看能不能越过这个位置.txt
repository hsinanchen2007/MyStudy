### 解题思路
先判断0点的位置，再对该位置之前的数进行遍历，看是否能跳过该0点的位置，如果不可以，则直接返回false ，可以，则继续遍历数组。

### 代码

```java
class Solution {
 public static boolean canJump(int[] nums) {
		boolean bool=true;
		if(nums.length==0) {
			return true;
		}
		if(nums[0]==0&&nums.length>1) {
			return false;
		}
		if(nums.length==1&&nums[0]==0) {
			return true;
		}
		int flag=1;//判断是否能跨过0的位置
		int j=0;
		int flag1=1;//判断是否数组中有0
        for (int i = 0; i < nums.length; i++) {
			if(nums[i]==0) {
				flag1=0;
				j=i;
				for(;j>=0;j--) {
					flag=1;
					if((nums[j]+j)>i&&j!=nums.length-1) {    //判断如果不是最后一个位置，该位置之前的进行遍历，如果nums[j]+j>i，则说明可以过0点，如果小于，则说明过不去，返回false
						flag=0;
						break;
					}
					if((nums[j]+j)>=i&&j==nums.length-1) {     //判断如果是最后一个位置，该位置之前的进行遍历，如果nums[j]+j>=i，则说明可以过0点，如果小于，则说明过不去，返回false
						flag=0;
						break;
					}
					
				}
				if(flag==1) {
					return false;
				}
			}
		}
        if(flag1==1||flag==0) {
			return true;
		}
        return bool;
    }
}
```