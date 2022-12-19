### 解题思路
我自己先想了一个双指针的思路，和官方的差不多，所以思路我就不写了
我发现官方的那个判断位置if(nums[i]！=nums[j])这里应该要改
因为这个方法是nums[j]把nums[i+1]覆盖
举个例子数组为 1,1,2,2,2,3,4,5,5,6,6....max
按照官方的判断先把1,2,3,4,5,6...max覆盖到前面来，但是后面还有元素
依然还要判断就会导致return i+1 的返回值大于[1,max]的长度
所以当用i+1截取输出的时候会多出很多元素

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length==0)
			return 0;
		int i=0;
		for(int j=1;j<nums.length;j++) {
			if(nums[i]<nums[j]) {
				nums[i+1]=nums[j];
				i++;
			}
		}
		return i+1;
    }
}
```