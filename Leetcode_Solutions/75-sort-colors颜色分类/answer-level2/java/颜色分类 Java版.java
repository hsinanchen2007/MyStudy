```java
public class Solution{	
	/*
	 * 一次遍历：荷兰国旗问题
	 * start指向开头最后一个0元素的后一个元素，end指向末尾第一个2元素的前一个元素，i指向当前元素
	 * While i <= end:
			若 nums[i] = 0 ：交换第i个 和 第start个 元素，并将指针都向右移。
			若 nums[i] = 2 ：交换第i个和第 end个元素，并将 end指针左移 。
			若 nums[i] = 1 ：将指针i右移。
	 */
	public static void sortColors(int[] nums) {
		int start = 0; //指向开头最后一个0元素的后一个元素
		int end = nums.length-1; //指向末尾第一个2元素的前一个元素
		int i = 0; //遍历整个数组
		int temp = 0; //辅助变量，用于交换
		while(i <= end) {
			if(nums[i] == 1) {  
				//如果当前元素为1，则不改变位置，遍历下一个元素
				i++;
			}else if(nums[i] == 0) {
				//如果当前元素为0，则与start元素交换，start和i后移一位
				temp = nums[i];
				nums[i] = nums[start];
				nums[start] = temp;
				start++;  
				i++;   // 因为左边一定是都扫描过的, nums[i]的的值是0。一定要后移一位继续扫描。
			}else {  //nums[i] == 2
				//如果当前元素为2，则与end元素交换，end前移一位
				temp = nums[i];
				nums[i] = nums[end];
				nums[end] = temp;
				end--;  // 右边交换完，nums[i]是之前的nums[end]的值，这个值是没有被扫描过的，所以需要继续判断nums[i]的值。
			}
		}
	}
}
```
