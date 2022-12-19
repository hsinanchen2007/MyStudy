### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
int L = 0;// 找到大于0的元素
		int R = nums.length - 1;// 找到小于2的元素
		while (L < R) {
			while (L < R && nums[L] == 0) {
				L++;
			}
			while (L < R && nums[R] == 2) {
				R--;
			}
             if (L < R && nums[L] == 1 && nums[R] == 1) {
				int lt = L;
				int rt = R;
				boolean flag = false;// 判断有没有全1 的可能
				for (; lt < R && rt > L;) {
					if (nums[lt] == 0 ) {
						flag = true;
						nums[lt] = 1;
						nums[L] = 0;
						break;
					}
					else if(nums[rt] == 2){
						flag=true;
						nums[R] = 2;
						nums[rt] = 1;
						break;
					}
					lt = nums[lt] == 0 ? lt : (lt + 1);
					rt = nums[rt] == 2 ? rt : (rt - 1);
				}
				if (flag) {
					continue;
				} else
					break;

			}
			else if (L < R ) {// 这三种情况直接交换
				int temp = nums[R];
				nums[R] = nums[L];
				nums[L] = temp;
			} 

		}
	}
}
```