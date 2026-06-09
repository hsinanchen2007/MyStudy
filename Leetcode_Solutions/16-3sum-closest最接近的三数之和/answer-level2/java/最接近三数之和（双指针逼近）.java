 //先进行排序，确定一个nums[i];然后从剩余元素的两端逐渐取值，逼近最小值

### 代码
```java**粗体**
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int len=nums.length;
	Arrays.sort(nums);
	int number=nums[0]+nums[1]+nums[2];
	if(len>=3) {
		for(int i=0;i<len-2;i++) {
			int Left=i+1;
			int Right=len-1;
			int sum=0;
		while(Left<Right) {
			sum=nums[i]+nums[Left]+nums[Right];
			if(Math.abs(sum-target)<Math.abs(number-target)) {
				number=sum;
			}
			if(sum-target>0) {
				Right--;
			}else if(sum-target<0) {
				Left++;
			}else {
				break;
			}
		}
		}
	}
	return number;
    }
}
```