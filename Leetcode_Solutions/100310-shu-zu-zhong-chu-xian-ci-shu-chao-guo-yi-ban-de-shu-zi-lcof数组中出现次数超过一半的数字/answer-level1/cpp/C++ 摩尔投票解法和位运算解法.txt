### 解题思路

#### 摩尔投票解法
利用题目所给数组特性，所求元素在数组中出现次数超过一半
设置两个变量：
result//记录当前元素值
times//记录次数
当我们遍历到下一个数字的时候，如果下一个数字和我们之前保存的数字相同，则次数+1；如果下一个数字和我们之前保存的数字不同，则次数-1.如果次数为0，那么我们需要保存下一个数字
，并把次数设为1.

#### 位运算解法
因为题目中定义的众数大于n/2，所以对所有数字的二进制的第i位的'1'进行统计，
如果‘1’的个数大于n/2，那么众数的二进制第i位一定是‘1’
进而求得众数

### 代码

#### 摩尔投票解法
```cpp
class Solution
{
public:
	int majorityElement(vector<int>& nums) {
		int result=nums[0];
		int times = 1;
		for (vector<int>::iterator it=nums.begin()+1;it!=nums.end();it++)
		{
			//次数为0，则更新result
			if (times == 0) {
				result = *it;
				times = 1;
			}
			//相等，次数+1
			else if(result==*it)
			{
				times++;
			}
			//不相等，次数-1
			else
			{
				times--;
			}
		}
		return result;
	}
};
```
#### 位运算

```cpp
class Solution {
public:
	int majorityElement(vector<int>& nums)
	{
		int ans = 0;
		for (int i=0;i<32;i++)
		{
			int t = 1 << i;
			int cnt = 0;
			for (int j=0;j<nums.size();j++)
			{
				if (nums[j]&t)//与，求第i位出现1的次数
				{
					cnt++;
				}
			}
			if (cnt > (nums.size() / 2)) ans |= t;//在第i位添上1
		}
		return ans;
	}
};
```