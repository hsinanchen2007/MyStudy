![2019122101.PNG](https://pic.leetcode-cn.com/22efdceee25c04d1e50738c4c76b8de42ddd54ab4c79c170cb35b6ef99ebed72-2019122101.PNG)
### 解题思路
//遍历一遍数组,设置三个变量:firstMax(记录遍历过程中出现的最大数),firstIndex(记录遍历过程中最大数的索引值),
//secondMax(记录遍历过程中出现的第二大的数),
//整个遍历完成后:用firstMax与secondMax进行除法运算,除法存在两种情况:
//1) secondMax不为0,firstMax/secondMax大于等于2,则返回firstIndex;
//2) secondMax为0,firstMax不为0,则返回firstIndex;
//否则返回-1;
### 代码
```java
class Solution {
    public int dominantIndex(int[] nums) {
    	int firstMax = 0;
    	int secondMax = 0;
    	int firstIndex = 0;
    	int i = 0;
    	//while循环遍历一遍数组,找到最大值和第二大的值
    	while(i<nums.length) {
    		if(nums[i]>=firstMax) {
    			secondMax = firstMax;
    			firstMax = nums[i];
    			firstIndex = i;
    			i++;
    		}else if(nums[i]<firstMax) {
				if(nums[i]>secondMax) {
					secondMax = nums[i];
				}
    			i++;
    		}
    	}
    	//对第一大的值和第二大的值进行大小判断,firstMax至少是secondMax的两倍大,则返回firstIndex,否则返回-1
    	if(secondMax!=0) {
    		if((firstMax>>1)>=secondMax) {
    			return firstIndex;
    		}
    	}else if(secondMax==0&&firstMax!=0) {
    		return firstIndex;
    	}
    	return -1;
    }
}
```