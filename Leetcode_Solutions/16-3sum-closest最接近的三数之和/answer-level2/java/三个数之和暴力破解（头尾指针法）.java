### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
      Arrays.sort(nums);
		boolean pan;
		int xiao = Integer.MAX_VALUE;
		int j,k,x;
		int end = 0;
		for(int i=0;i<nums.length-2;i++) {
			j = i + 1;
			k  = nums.length-1;
			while(j!=k) {
				pan = Math.abs((x=nums[i]+nums[j]+nums[k])-target)<xiao?true:false;
				if(pan) {
					end = nums[i]+nums[j]+nums[k];
					xiao = Math.abs(nums[i]+nums[j]+nums[k]-target);
				}
				if(x>target)
					k--;
				else
					j++;
			}
		}
        return end;     
    }
}
```这题能自己做出来很开心，说明我进步了。定义3个数分别为i,j,k,首先选中一个数i，从0到length-2循环（因为要选出3个数）,j指向i的下一个数，k指向数组的最后一个数。然后nums数组对应这三个位置相加的结果减去这个target的绝对值与pan比较。如果比较小，那么end就赋值为这三个数的总和。最小的数也是这三个数的总和减去target的绝对值。然后如果这三个数的总和x比target大，那么末尾的指针k就往左走，注意x和end是不一样的。如果总和比target小头指针j就往右走。这样能节省一些不必要的比较。