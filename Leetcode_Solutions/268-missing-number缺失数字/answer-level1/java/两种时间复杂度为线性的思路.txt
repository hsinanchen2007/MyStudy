两种时间复杂度为线性的思路：1.计算0到n的和，再减去数组的各项，剩下的就是所求值；或数组各项相加再用0到n的和去减。2.使用一个数组temp，长度为nums+1,遍历nums，nums的值作为temp的下标并赋值为1，最后遍历temp,找出值为0的那个下标。
```
	public static int missingNumber(int[] nums){
//      第一种思路：
		int sum = 0,N = nums.length;
		for (int i = 0; i < N; i++) {
			sum += nums[i];
		}
		return	N*(N+1)/2-sum;

//		int sum = 0,N = nums.length;
//		sum = (N*(N+1))/2;
//		for (int i = 0; i < N; i++) {
//			sum -= nums[i];
//		}
//		return	sum;

//      第二种思路：
//		int res = 0;
//		int[] temp = new int[nums.length+1];
//		for (int i = 0; i < nums.length; i++) {
//			temp[nums[i]] = 1;
//		}
//		for (int i = 0; i < temp.length; i++) {
//			if(temp[i]==0)
//				res = i;
//		}
//		return res;
	}
```

