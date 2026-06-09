### 解题思路
>1. 把数组排序；
> 2. 统计数组中0的个数；
> 3. 最后，统计排序后数组中相邻数字的间隔总数。
	3.1 如果空缺总数小于或者等于0的个数，则为连续的
	3.2 否则为不连续


### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        Arrays.sort(nums);
		int count0=0;
		for(int k:nums) {
			if(k==0) {count0++;
			}else {break;}
		}
		int small=count0,big=small+1;
		int numOfGap=0;
		while(big<nums.length && flag ) {
			if(nums[small]==nums[big]) {return false;}
			numOfGap+=nums[big]-nums[small]-1;
			small=big;big++;
		}
		return (numOfGap>count0)?false:true;
    }
}
```