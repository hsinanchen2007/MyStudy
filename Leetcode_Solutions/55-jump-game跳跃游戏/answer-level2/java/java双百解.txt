### 解题思路
缓存前序可达的最大index，详细思路https://blog.csdn.net/qq_23134039/article/details/103472586

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
       if(nums==null||nums.length==0) {
			return false;
		}
		int max = nums[0];     //前序可达的最大值
		for(int i=0;i<=nums.length-1;i++) {
			if(max>=nums.length-1) {   //可达末尾
				return true;
			}else if(max<i) {   //前序不可达当前index
				return false;
			}
			if(i+nums[i]>max) {   //更新可达点
				max=i+nums[i];
			}
		}
		return true;    //能完成遍历即可
    }
}
```