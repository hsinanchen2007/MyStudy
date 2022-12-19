### 解题思路

首先这种字典序的本质就是，通过移动某个数字，来让整个字符串增加【最小】的量；

规则1： 如果 从后往前,每一个数都比前面的大的话，那么这个数组没有可移动性，可以直接翻转；
规则2： 寻找一个数字位置 target_i ，要求 target_i 之前有位置 j  && nums[j] < target_i  . 如果有多个target_i 和 j ，选择数值最大的j
        (因为j的值越大，他对应的位越小；例如 [1,2,3,4] 中  j = 3 那么调整增加的就是个位数级别，j=2,那么就是十位数级别）

处理办法： 将 target_i 插入到最大的 j 之前，实现最小的增加。然后删除掉 j 位置的数字；
          最后将 j+1 之后的数字排序，形成最小序列。就形成了最小增加量


例如  [1,4,6,8,5,1,0,0]
target_i = 4 ; nums[target_i]=5； j = 1, nums[j]=4
target_i = 3 ; nums[traget_i]=8； j = 2, nums[j]=6;

选择最大的 j = 2；对应的 target=3;

然后把 nums[3] 移动到 nums[2]之前，实现最小量的增长；
然后对后面的 排序，形成最小序列即可。

感觉在做脑筋急转弯，有点捉急。

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
   
	if (nums.empty()||nums.size()<2) return;

	int max_j = -1;
	int target_i = -1;

	// 寻找第一个非零值，然后要求 其前面有比他小的数字
	for (int i = nums.size()-1; i > 0; i--)
	{
		if (nums[i] == 0)
			continue;

		for (int j = i - 1; j >= 0; j--)
		{
			if (nums[j] < nums[i])
			{
				if (max_j < j)
				{
                    // j 就是数的第 j 位，j越大，说明数字增加的越小
					max_j = j;
					target_i = i;
				}
					
			}

		}
	}

	if (max_j != -1)
	{
        //经过了交换之后，确定了需要交换的位置，将 j 插入到 i 前面，然后将后面的排序形成最小的序列
		int t = nums[target_i];
		nums.erase(nums.begin() + target_i);
		nums.insert(nums.begin() + max_j, t);
		sort(nums.begin() + max_j + 1, nums.end());
		return;
	}

	reverse(nums.begin(), nums.end());
	while (!nums.empty() && nums[0] == 0)
		nums.erase(nums.begin());
    }
};
```

![image.png](https://pic.leetcode-cn.com/96cb2f3f7d8f1ee5511384a5c5a95d06e97579bb9c2e07bd16068d39e504a2f2-image.png)
