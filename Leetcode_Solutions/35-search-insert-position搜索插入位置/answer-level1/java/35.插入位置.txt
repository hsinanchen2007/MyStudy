### 运行结果
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :45 MB, 在所有 Java 提交中击败了5.07%的用户
### 解题思路
- 编写了一个二分查找的程序；
- 通过条件分支结构（if语句）来查找不存在target的插入坐标；

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int index=binarySearch(nums, 0, nums.length-1, target);
		if(index==-1) {
			if(target>nums[nums.length-1]) {
				index=nums.length;
			}else if(target<nums[0]) {
				index=0;
			}else {
				while(index==-1) {
					index=binarySearch(nums, 0, nums.length-1, target++);
					
				}
			}
			
		}
		return index;
    }
    public static int binarySearch(int[] nums,int left,int right,int target) {
		if(left>right) {
			return -1;
		}
		int mid=(left+right)/2;
		int midVal=nums[mid];
		if(midVal<target) {
			return binarySearch(nums, mid+1, right, target);
		}else if(midVal>target) {
			return binarySearch(nums, left, mid-1, target);
		}else {
			return mid;
		}
	}
}
```