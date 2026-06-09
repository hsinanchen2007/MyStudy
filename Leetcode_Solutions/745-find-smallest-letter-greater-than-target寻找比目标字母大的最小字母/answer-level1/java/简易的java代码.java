### 代码

```java
class Solution {
    public char nextGreatestLetter(char[] letters,char target){
		// 转为字符对应的ASCII码进行比较
		int size = letters.length;
		int[] nums = new int[size];
		for(int i=0;i<size;i++){
			nums[i] = letters[i];
		}
		Arrays.sort(nums);
		int myTarget = target;
		if(myTarget >= nums[size-1]){
			// 先判断，可以优化时间复杂度
			return (char) nums[0];
		}
		for(int i=0;i<size;i++){
			if(nums[i]>target){
				return (char) nums[i];
			}
		}
		return ' ';
	}
}
```