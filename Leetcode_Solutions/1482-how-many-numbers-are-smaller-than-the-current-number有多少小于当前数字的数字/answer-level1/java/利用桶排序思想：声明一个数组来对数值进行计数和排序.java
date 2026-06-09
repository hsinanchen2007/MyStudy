![2020030501.PNG](https://pic.leetcode-cn.com/42538417d87794e6fdf096dc762ba8c58f7e416d042408df82a537658d634211-2020030501.PNG)

**### 解题思路
计数数组

由提示知道,数组nums[i] (i>=0&&i<nums.length) 中的值的范围为[0,100],

因此声明一个计数数组rec (数组rec的长度声明为101),

先遍历一遍数组nums, 每遍历到一个数nums[i] (记index=nums[i]), 则在记录数组中,对应的下标加1,即rec[index]++;

再遍历一遍记录数组rec (j<101), 声明int型cnt, cnt记录比数值j小的数值数目,

若rec[j]>0, 则更新rec[j]的值,即rec[j]=cnt,

最后再遍历一遍数组nums, 记index=nums[i] (i<nums.length), 将nums[i]的值更新为比nums[i]大的值的数目, 即nums[i]=rec[index];
**
最后返回数组nums即可.

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int LENGTH = 101;
    	int[] rec = new int[LENGTH];
    	for(int i=0;i<nums.length;i++) {
    		rec[nums[i]]++;
    	}
    	int cnt=0;
    	int temp=0;
    	for(int i=0;i<rec.length;i++) {
    		if(rec[i]!=0) {
    			temp=rec[i];
    			rec[i]=cnt;
    			cnt+=temp;
    		}
    	}
    	for(int i=0;i<nums.length;i++) {
    		nums[i]=rec[nums[i]];
    	}
    	return nums;
    }
}
```