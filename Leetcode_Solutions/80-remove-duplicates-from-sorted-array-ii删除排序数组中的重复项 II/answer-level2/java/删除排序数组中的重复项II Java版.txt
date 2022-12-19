```java
public class Solution{
	/*
	* 若当前的三个元素是：[a b c]，i指向中间的b,j从c开始扫描
	* 1.如果a==c，即形如[0 0 0]，则i应该指向b;
	* 2.如果a!=c，即形如[0,0,1],[0,1,1],[0,1,2],则i指向c  
	* 直接比较当前3个元素:若当前元素不等于指向i-1的元素，则i后移一位，并将nums[j]的值赋予nums[i]
	*/
	public static int removeDUplicatesSkipCompare(int[] nums) {
		int i = 1; //i指向新数组中最后一个元素
		for(int j = 2; j < nums.length; j++) {
			 //如果当前元素不等于指向i-1的元素，则i后移，并将nums[j]的值赋予nums[i]
			if(nums[j] != nums[i-1]) {
				i++;
				nums[i] = nums[j];
			}
		}
		return i+1;
	}

	/*
	* 遍历数组，当有两个连续的数字重复的时候就要进行判断，先保存当前val，然后再复制两个重复的元素，
	* 接着指针i开始跳过多余的重复元素即可;
	* 如果当前元素只有1个，直接赋值；
	* 如果当前元素至少2个，i和j先移动2位，再判断后面一位是否和之前的值相同，如果相同，j继续扫描，i不动
	*/
	public static int removeDuplicatesCompare(int[] nums) {
		if(nums == null || nums.length == 0) return 0;
		int i = 0; //i指向从0开始的符合条件的数组的最后一个元素
		for(int j = 0; j < nums.length;){
			//当有两个连续的数字重复的时候就要进行判断
			if(j < nums.length -1 && nums[j] == nums[j+1]) { 
				//先保存当前val，然后再复制两个重复的元素
				int val = nums[j];
				nums[i++] = nums[j++];
				nums[i++] = nums[j++];
				//找到下一个与val不同的元素
				while(j < nums.length && nums[j] == val) {
					j++;
				}
			}else {
				nums[i++] = nums[j++];
			}
		}
		return i;
	}
}
```