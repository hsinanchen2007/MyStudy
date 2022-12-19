```java
public class Solution{
	/*
	 * 双指针：i指向数组开头，j指向数组结尾。数组是升序排列
	 * 	如果当前两个元素之和等于目标值，则直接返回索引值+1 (因为题目要求索引从1开始)；
	 * 	如果大于target，需要选择小一点的数；
	 * 	如果小于target，需要选择大一点的数。
	 */
	public static int[] twoSum(int[] numbers, int target) {
		int i = 0; //指向数组开头
		int j = numbers.length-1; //指向数组末尾
		while(i < j) {
			//如果当前两个元素之和等于目标值，则直接返回索引值+1 (因为题目要求索引从1开始)
			if(numbers[i] + numbers[j] == target) {  
				return new int[] {i+1,j+1}; 
			}else if (numbers[i] + numbers[j] > target) { 
				//如果大于target，需要选择小一点的数
				j--;
			}else {
				//如果小于target，需要选择大一点的数
				i++;
			}
		}
		return new int[] {0,0};
	}
}
```