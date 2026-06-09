### 解题思路
采用倒序查找，找出已遍历区段的符合的最大元素与次大元素，难点在于次大元素的更新选择。后续只需判断是否存在元素小于次大元素即可https://blog.csdn.net/qq_23134039/article/details/103611818

### 代码

```java
class Solution {
    public boolean find132pattern(int[] nums) {
      	if (nums == null || nums.length < 3) {
			return false;
		} // 更新更大的max和min 难点在于min的取值
		int start = nums[nums.length - 1];  //最后一个元素
		int min = nums[nums.length - 1];	//后段符合的第二大元素
		int max = nums[nums.length - 1];	//后段符合的最大元素
		int mai = 0; //前序所有波峰的前一位最大元素index
		int mii =0;	//第一轮若为递减则缓存第一个波谷的index
		int bf = nums[nums.length - 1]; // 后一位元素
		int flag = 0; // 前序变化方向 1递增 -1递减
		int flag2 = 0; // 是否相等
		int flag3 = 0; // 第一轮变化标志，找到第一个波峰则变为1
		int bc = 0; //相等出现次数缓存
		for (int i = nums.length - 2; i >= 0; i--) {
			int num = nums[i];
			if (num > bf) { // 递增
				if (flag == -1) { // 前序递减 即为波谷
					if (flag3 == 0) { //第一次检索为波谷
						min = bf;
						mii=i+1;
					}
					if (flag3 == 1 && bf < min) { // 前序存在波峰且该波谷小于min
						return true;
					}
				}
				flag = 1;
				flag2 = 0;
				bc = 0;
				bf = num;
			} else if (num < bf) { // 递减
				if (flag == 1) { // 前序递增 即波峰
					if (flag3 == 0) { // 前序不存在波峰
						max = bf; // max即为bf min需综合判断
						min = nums[i + 2 + bc]; // min初始为波峰后一位
						if (max > start) { // 波峰大于最后一位
							min = Math.max(start, min);// 更新min为最后位与min缓存的较大者
						} else { // 否则需遍历前段
							for (int m = nums.length - 1; m >= mii; m--) {
								if (nums[m] < bf) { // 找到小于波峰的最大一位
									min = Math.max(min, nums[m]); // 该位元素与缓存的较大值
									break;
								}
							}
						}
						mai =i;
						flag3 = 1;
					} else if (bf > max) { // 波峰更高
						// min综合判断
						min = Math.max(max, nums[i + 2 + bc]); // 前段波峰与及当前波峰前一位较大值
						max = bf;// 更新max
						if (min < start) { // 缓存值
							for (int m = nums.length - 1; m >= mii; m--) {
								if (nums[m] < bf) { // 同样找到小于波峰最大一位
									min = Math.max(min, nums[m]);
									break;
								}
							}
						}						
					} else if (Math.max(nums[mai], nums[i + 2 + bc]) > min) { //前一波峰前一位与当前
						min = Math.max(nums[mai], nums[i + 2 + bc]);	//后一位的较大值大于min,则更新
						max = bf;
					}
					mai = nums[i]>nums[mai] ? i:mai;  //当前i为波峰前一位，判断是否需要更新
				}				
				bf = num;
				flag = -1;
				flag2 = 0;
				bc = 0;
			} else {		//相等		
				flag2 = 1;			
				bf = num;
				bc++;	//记录相等出现次数
			}
		}
		if (flag3 == 1 && bf < min)
		{ // 对应结束时持续递减获得最小值
			return true;
		}
		return false;
    }
}
```