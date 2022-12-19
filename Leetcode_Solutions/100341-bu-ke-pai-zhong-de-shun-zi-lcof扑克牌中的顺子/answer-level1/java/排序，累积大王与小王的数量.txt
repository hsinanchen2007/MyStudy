将数组进行排序，然后将数组中的0进行抽取，不进行比较，比较剩余数值中的相邻两个数值之间的差值。
```
public boolean isStraight(int[] nums) {
	Arrays.sort(nums);
	//累积0的个数，也就是大王与小王的个数
	int zero=0;
	for(int i=0;i<nums.length;i++) {
		if(nums[i]==0) {
			zero++;
		}else {
			break;
		}
	}
	for(int i=1;i<nums.length;i++) {
		if(nums[i]==0) {
			continue;
		}
		if(nums[i]!=0 && nums[i]-nums[i-1]==0) {
			System.out.println("11111");
			return false;
		}
		if(nums[i-1]!=0 && nums[i]-nums[i-1]>3) {
			System.out.println(nums[i-1]+" "+nums[i]);
			System.out.println("2222222");
			return false;
		}
		if(nums[i]-nums[i-1]==2) {
			zero--;
		}
		if(nums[i]-nums[i-1]==3) {
			zero=zero-2;
		}
		if(zero<0) {
			System.out.println("333333333333");
			return false;
		}
	}
	return true;
}

```
