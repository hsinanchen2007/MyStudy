## 题解
这道题的难点是不能包含重复的答案，对于```[0,0,0,0,0]```这个数组，答案只有一个```[0,0,0]```。     
首先我们对数组先排序一次，在排好序的数组上，就很容判断前后元素是否相当，这样可以过滤掉重复的答案。    
再定义三个指针，```k```，```i```，```j```如下图所示   
![1.jpg](https://pic.leetcode-cn.com/a37e0d798132d6b67091d7c00cd281b65ff59e2001cd20972d4f892068f32577-1.jpg)
指针```i```从左往右移动，且始终比```k```大一位，这样就保证不会跟```k```重叠，   
指针```j```从右往左移动，且始终比```i```大，这样```i```和```j```就不会重叠，即三个指针都不会重叠。   
在这个基础上，实现我们的主要逻辑：   
- ```nums[k]>0```时，可以直接跳出循环，因为```nums[k]```都比0大了，后面的```nums[i]```和```nums[j]```肯定更大，三者加起来肯定大于0   
- ```nums[k]```和```nums[k-1]```相等，即前后元素重复了，需要过滤掉
- 如果```nums[i]+nums[j]+nums[k]>0```，即三者之和太大了，我们将```j```指针左移，因为三个数中最大的肯定是```nums[j]```，将```j```左移就可以减小三者之和。   
- 如果```nums[i]+nums[j]+nums[k]<0```，说明三者之和太小了，同理将```i```指针右移   
- 如果```nums[i]+nums[j]+nums[k]==0```，这就是要找的答案，将其保存起来，同时```i```右移，```j```左移
- ```i```和```j```在移动的过程中还需要判断前后元素是否重复   

![2.gif](https://pic.leetcode-cn.com/e3fa59cbf3ac1200a26a435d00e872f78ec940afd4ee1977b04c1f4dca45c14e-2.gif)
时间复杂度：O(n^2):排序O(nlogn)+循环比较O(n^2)   
空间复杂度：O(1)   

代码实现:
```java []
class Solution {
	public List<List<Integer>> threeSum(int[] nums) {
		if(nums==null) {
			return new ArrayList<List<Integer>>();
		}
		ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
		int n = nums.length;
		//正式处理之前，先将数组排序
		Arrays.sort(nums);
		//假设数组为[0,1,2,3,4,5,6,7,8,9,10]
		//第三个指针k最多到下标8位置，因为后面两个位置需要留给另外两个指针
		for(int k=0;k<n-2;k++) {
			//nums[k]>0，说明后面的元素肯定也大于0，最后结果肯定>0，故直接跳出
			if(nums[k]>0) {
				break;
			}
			//如果当前元素和前面一个元素一样，忽略重复元素
			if(k>0 && nums[k-1]==nums[k]) {
				continue;
			}
			//定义另外两个指针 i 和 j 
			int i = k+1;
			int j = n-1;
			while(i<j) {
				int tmp = nums[i]+nums[j]+nums[k];
				//如果三数之和>0，说明最右边的值太大了
				if(tmp>0) {
					--j;
					while(i<j && nums[j+1]==nums[j]) {
						--j;
					}
				}
				//如果三数之和<0，说明左边的值太小了
				else if(tmp<0) {
					++i;
					while(i<j && nums[i-1]==nums[i]) {
						++i;
					}
				}
				//三数之和等于0，保存结果
				//同时左指针往右移动，右指针往左移动，
				//如果移动过程中碰到重复元素，则继续移动
				else {
					List<Integer> list = new ArrayList<Integer>();
					list.add(nums[k]);
					list.add(nums[i]);
					list.add(nums[j]);
					res.add(list);
					++i;
					--j;
					while(i<j && nums[i-1]==nums[i]) {
						++i;
					}
					while(i<j && nums[j+1]==nums[j]) {
						--j;
					}
				}
			}
		}
		return res;
	}
}
```
```python []
class Solution(object):
	def threeSum(self, nums):
		if not nums:
			return []
		# 正式处理之前，先将数组排序	
		nums = sorted(nums)
		n = len(nums)
		res = []
		# 假设数组为[0,1,2,3,4,5,6,7,8,9,10]
		# 第三个指针k最多到下标8位置，因为后面两个位置需要留给另外两个指针
		for k in xrange(n-2):
			# nums[k]>0，说明后面的元素肯定也大于0，最后结果肯定>0，故直接跳出
			if nums[k]>0:
				break
			# 如果当前元素和前面一个元素一样，忽略重复元素	
			if k>0 and nums[k-1]==nums[k]:
				continue
			# 定义另外两个指针 i 和 j 	
			i,j = k+1,n-1
			while i<j:
				tmp = nums[i]+nums[j]+nums[k]
				# 如果三数之和>0，说明最右边的值太大了，
				if tmp>0:
					j -= 1
					while i<j and nums[j+1]==nums[j]:
						j -= 1
				# 如果三数之和<0，说明左边的值太小了		
				elif tmp<0:
					i += 1
					while i<j and nums[i-1]==nums[i]:
						i += 1
				# 三数之和等于0，保存结果
				# 同时左指针往右移动，右指针往左移动，
				# 如果移动过程中碰到重复元素，则继续移动
				else:
					res.append([ nums[k],nums[i],nums[j] ])
					i += 1
					j -= 1
					while i<j and nums[i-1]==nums[i]:
						i += 1
					while i<j and nums[j+1]==nums[j]:
						j -= 1
		return res
```
(全文完)

**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)



