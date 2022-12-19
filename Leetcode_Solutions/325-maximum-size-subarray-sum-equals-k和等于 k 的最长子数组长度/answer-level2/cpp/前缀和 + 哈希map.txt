计算所有的前缀和之后

我们从0-N遍历 前缀和

到S(i)的时候，我找S(0)~S(i-1), 看下 S(i)-S(?) = k;

然后（？到 i）的区间和 就是 k；

如果用普通查找很慢，所以我们想快点，所以把S(0)~S(i-1)存在 hash map里边。这样只用在map中 找 S(?) = S(i)-k
一下就找到了。

![image.png](https://pic.leetcode-cn.com/bcf3283d9936d2ea77bec7e7a61943dc738e9047dbe102b7807e2345435572a9-image.png)

```
class Solution {
public:
	int maxSubArrayLen(vector<int>& nums, int k) {
		vector<int> prefixsum;
		prefixsum.resize(nums.size(), 0);
		int sum = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			prefixsum[i] = sum;
		}


		unordered_map<int, int> mp; //前边的表示前缀和 ，后边int表示索引
		int maxlen = 0;
		int len = 0;
		mp[0] = -1;
		//这方法巧妙在 我只想找 i 之前的前缀和  正好 遍历的时候 mp就只存了i之前的前缀和，i之后的还没存
		for (size_t i = 0; i < nums.size(); i++) {
			//之前的前缀和里边有  和当前的前缀和 差k的
			if (mp.find(prefixsum[i] - k) != mp.end())
			{
				len = i - mp[prefixsum[i] - k];//当前的前缀和 之前的前缀和的 索引差就是区间长度。
				maxlen = max(len, maxlen);
			}

			//mp[prefixsum[i]] = i;//把前缀和加到map中  可能后边的会覆盖前边的，这样就找不到最长的了所以要判断一下,前边没出现过，再写入map
			if (mp.find(prefixsum[i]) == mp.end())
			{
				mp[prefixsum[i]] = i;
			}
		}

		return maxlen;
	}
};
```
