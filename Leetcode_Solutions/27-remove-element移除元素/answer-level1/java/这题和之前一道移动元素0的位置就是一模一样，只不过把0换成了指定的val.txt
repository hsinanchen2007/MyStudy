### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums==null) {
			return 0;
		}
		//第一次遍历的时候，j指针记录非val的个数，只要是非val的统统都赋给nums[j]
        int j = 0;
		for(int i = 0;i<nums.length;++i) {
			if(nums[i]!=val) {
				nums[j++] = nums[i];
			}
		}
		//非val元素统计完了，剩下的都是val了
		//所以第二次遍历把末尾的元素都赋为val即可
		for(int i=j;i<nums.length;++i) {
			nums[i] = val;
		}
        return j;
    }
}
```