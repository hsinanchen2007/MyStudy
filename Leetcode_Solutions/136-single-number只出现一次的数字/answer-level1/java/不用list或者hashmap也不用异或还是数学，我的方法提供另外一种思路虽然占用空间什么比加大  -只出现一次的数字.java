**解题思路**：其实我看到题目后越来越被他的说明迷惑到了，又是线性又是不用额外空间；我就不敢想别的方法只是想办法在这个数组上做手脚来解决这个题，只在这个数组上；思来想去只能一个一个标记了（类似双指针一个一个像后边找）
```java
public int singleNumber(int[] nums) {
		 int j;
		 for(int i=0;i<nums.length;i++) {
			 if(nums[i]==-1) continue;
			 int targer = nums[i];
			 for(j=i+1;j<nums.length;j++) {
				 if(nums[j]==targer) { nums[j]=-1;break;}
			 }
			 if(j==nums.length) return targer;
		 }
		 return -1;
	    }
```
提交虽然通过了但是耗时也是惨不忍睹的，那就想办法在这种方法上优化一下：**增加个排序会好很多的**
也算是一种思路吧，然后异或是真的nb！