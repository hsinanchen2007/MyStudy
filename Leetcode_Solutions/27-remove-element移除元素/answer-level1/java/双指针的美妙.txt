不花费额外空间，一趟排序走完，这就是我们的要求。

让我们先分析一遍过程：
1. 创建一个指针j
2. 循环nums，指针变量为i
3. 当nums[i]!=val时，j随着i往后走一步,j++,外层i++
4. 当nums[j]==val时，j停住了，因为此时j处的位置数值时要舍弃的，也就是要改为下个不等于val的nums[i]

这样循环过程就结束了，怎么能保证把下个不等于val的nums[i]值复制到值等于val的位置呢，也就是在nums[i]!=val时，让nums[j]=nums[i]

这样做的话，在刚开始没有出现val值时，i和j处在同一位置，赋值也不影响。出现了val之后，j不动，i继续移动到不为val的位置，此时继续赋值，在之后每个不为val的数值，都被上提到j处，也就是上提了值为val的个数的距离，达到了题目要求的效果。
```
    public static int removeElement(int[] nums, int val) {
		 int j=0;
		 for(int i=0;i<nums.length;i++) {
			if(nums[i]!=val) {
				nums[j]=nums[i];
				j++;
			}
		 }
		 return j;
	}
```


