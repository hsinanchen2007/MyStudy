### 解题思路
第一轮全部异或走一遍，最后得到的肯定是 num1 ^ num2 的结果num
找到这个结果的其中一个非零位，即是1的二进制位，这个位是1，说明 num1和num2中在这个位上肯定一个是0一个是1
所以用num再走两遍
一遍 num 只与 刚才选的那位是1的数进行异或，最后剩下num1和num2的其中一个
另一遍 num 只与 选的那位不是1的数进行异或，最后剩下的就是要求的另一个数
~~~
//关于如何找到非零位：
int flag = 1;
int t = num;
while((t & 1) == 0) {
	t >>= 1;
	flag <<= 1;
}
//关于如何判断某位是否为1
(nums[i] & flag) == flag;//为1
(nums[i] & flag) == 0;   //为0
~~~


### 代码

```java
class Solution {
    public int[] singleNumber(int[] nums) {
        int[] ans = new int[2];
		int num = nums[0];
		int len = nums.length;
		for(int i = 1; i < len; i++) {
			num ^= nums[i];
		}
		// System.out.println(num+","+Integer.toBinaryString(num));
		ans[0] = num;
		ans[1] = num;
		int flag = 1;
		int t = num;
		while((t & 1) == 0) {
			t >>= 1;
			flag <<= 1;
		}
		// System.out.println(flag+","+Integer.toBinaryString(flag));
		for(int i = 0; i < len; i++) {
			if((nums[i] & flag) == flag) {
				ans[0] ^= nums[i];
			}
		}
		for(int i = 0; i < len; i++) {
			if((nums[i] & flag) == 0) {
				ans[1] ^= nums[i];
			}
		}
		return ans;
    }
}
```