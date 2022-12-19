### 解题思路
这道题我一开始想了很久，想到一个自认为很妙的方法，却debug了超久。（就是下面的法一与法二。
后来发现可以无脑做，害...
详见代码。

### 代码
#### **法一：只判断是否可以跳过“0”**
![微信图片_20200314184607.png](https://pic.leetcode-cn.com/ce745f36c78d0841a1c08eb28b94647ed950c09cf9c391b8fa370657891a3612-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200314184607.png)

经过思考可以发现，只有在0存在的时候才有可能跳不到最后，所以只需要判断能不能跳过数组中的“0”。
故可以先通过stl里面的find函数进行初始判断，**提速！！**
并且，在两个相邻的0之间的点都是可以跳到的。比如说[...,0,x_1,x_2,...,x_k,0,...]中，当已经判断了可以跳过第一个0的时候，可以直接判断能否跳过第二个0，中间的x_k肯定可以跳到。（因为都是非0值）

*而在形成了以上的基本思路后，有以下几点细节需要注意：*
1. 要判断是否存在连“0”的情况，如果存在，则要看能否跳过所有这些连续的0，而不是只跳过第一个。
2. 要判断“0”是否是nums数组的最后一个元素，如果是的话就不用“跳过”，可以“到达”就可。
3. 每次判断能否跳过“0”的时候，都要从数组的第一个元素开始判断，（也就是下面的start=0）而不是从前面一个0的下一位置开始判断。（因为前面可能出现跳过几个0的情况）

注：在看题解的时候，发现有类似的思路，不过是从后面开始判断，并且每个元素都进行判断。
但其实没必要，只需判断0就可以。（证明见上）

```cpp
class Solution {
public:
bool canJump(vector<int>& nums) {
	auto iter = find(nums.begin(), nums.end(), 0);//判断数组中含不含0
	if (iter == nums.end() || nums[0] >= nums.size() - 1)
		return true;
	vector<int> zero;//记录0的位置
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
			zero.push_back(i);
	}
	for (int i = 0; i < zero.size(); i++)
	{
		bool flag = false;
        int start=0;//！！每次都要从最前面判断
		int first_zero_idx = zero[i];
		while (i + 1 < zero.size() && zero[i + 1] - zero[i] == 1)
			i++;//处理存在的连0的情况
		while (start != first_zero_idx)
		{
			if (zero[i]==nums.size()-1&&nums[start]>=(zero[i]-start)||nums[start] > (zero[i] - start))//要看这个0是不是数组的最后一个数，如果是的话就不用“跳过”，可以“到达”就可
			{
				flag = true;
				break;
			}
			start++;
		}
		if (flag == false)
			return false;
	}
	return true;
}
};
```
#### **法二：优化法一，可以将start设为从0的前一位置开始向前遍历。（直觉上会降低复杂度）**
![微信图片_20200327010254.png](https://pic.leetcode-cn.com/4260821a1b01ea4e883b1f91cc7dbe0749532785d8823ae5c61279115d798ae3-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200327010254.png)

```
bool canJump(vector<int>& nums) {
	auto iter = find(nums.begin(), nums.end(), 0);
	if (iter == nums.end() || nums[0] >= nums.size() - 1)
		return true;
	vector<int> zero;//记录0的位置
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
			zero.push_back(i);
	}
	for (int i = 0; i < zero.size(); i++)
	{
		bool flag = false;
		int first_zero_idx = zero[i];
		int start = first_zero_idx - 1;
		while (i + 1 < zero.size() && zero[i + 1] - zero[i] == 1)
			i++;
		while (start != -1)
		{
			if (zero[i] == nums.size() - 1 && nums[start] >= (zero[i] - start) || nums[start] > (zero[i] - start))
			{
				flag = true;
				break;
			}
			start--;
		}
		if (flag == false)
			return false;
	}
	return true;
}
```
#### **法三：一次遍历，并在每次访问元素时，比较并记录当前可访问的最大位置。**
精妙之处在于，当发现可访问的最大位置<当前访问位置时，直接退出。
简洁明了！！（但感觉比较难想到这么凝练）
![微信图片_20200327010308.png](https://pic.leetcode-cn.com/2488c4e2b2e9e335951b0f6dc798c63aaf03f74470b580e7319c623055cf667b-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200327010308.png)

```
bool canJump(vector<int>& nums) 
{
	int k = 0;
	for (int i = 0; k < nums.size()-1; i++)
	{
		if (i > k) return false;
		k = max(k, i + nums[i]);
	}
	return true;
}
```
