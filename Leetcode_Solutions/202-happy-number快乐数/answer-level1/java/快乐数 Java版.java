```java
public class Solution{
    /*
	 * 快慢指针：
	 * 使用“快慢指针”思想找出循环：“快指针”每次走两步，“慢指针”每次走一步，当二者相等时，即为一个循环周期。
	 * 此时，判断是不是因为1引起的循环，是的话就是快乐数，否则不是快乐数。
	 */
	public static boolean isHappy(int n) {
		int slow = n;
		int fast = getSquareSum(n);
		while (slow != fast) {
			slow = getSquareSum(slow);
			fast = getSquareSum(fast);
			fast = getSquareSum(fast);
		}
		return slow == 1;
	}

	// 计算当前元素的各个位数的平方和
	private static int getSquareSum(int n) {
		int sum = 0;
		while (n > 0) {
			int bit = n % 10;
			sum += bit * bit;
			n /= 10;
		}
		return sum;
	}

	/*
	 * 使用HashSet存放中间的计算结果，如果出现重复，则出现
	 */
	public static boolean isHappyHashSet(int n) {
		Set<Integer> set = new HashSet<>(); // 存放已有结果
		int sum = 0;
		while (true) {
			// 计算n的各个位的平方和
			while (n != 0) {
				sum += Math.pow(n % 10, 2);
				n /= 10;
			}
			// 该数是快乐数
			if (sum == 1) {
				return true;
			}
			// 如果set中不包含该元素，则添加该元素，并继续判断
			if (!set.contains(sum)) {
				set.add(sum);
				n = sum; // 新的n是这次求得的和
				sum = 0; // sum需要置0
			} else { // 如果set中包含该元素，说明出现重复元素，进入了死循环，则直接返回false
				return false;
			}
		}
	}
}
```