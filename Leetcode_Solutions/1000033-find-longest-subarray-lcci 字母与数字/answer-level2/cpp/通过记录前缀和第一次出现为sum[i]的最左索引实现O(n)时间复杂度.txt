这一看这道题，其实思路很明显。首先计算每一个字字符串的性质，比如说我令当字符串是字母序列，那么记为-1，如果是数字序列，记为+1. 那么就是求最长的连续子数组，这个子数组的区间内所有元素 和为目标值0.

        关键就是如何求出来目标值为0的最长子数组长度呢？首先我们可以想到一个O(n^2)的办法，也就是首先求出前缀和sum[i],sum[i]表示的是0~i的数组的元素和为多少。那么sum[i] - sum[j]表示的就是从j+1~i位置所有的元素的和。两层遍历就可以求出最长的子数组了。

        有没有更好的办法呢？实际上是有的，最终的算法复杂度是O(n)。假设我们考虑sum[i]的情况如下：

         +1， +2，+3， +2， +2，+3，+2，+1， 0， -1，-2，-1, 0，+1，+2，+3，+2...

我们看加粗的+3，表示在这个位置sum[2] == sum[5] == sum[15] == +3. 假设我们遍历到第二个+3的位置也就是index = 5索引位置，这个时候，如果我们知道最左边索引2位置也有一个3，那么我们可以清楚地得知 从索引2后一位 到 索引5 的和是0. 我们在看索引15的sum[15] == 3, 当遍历到这一位的时候，我们如果知道最左边索引2的位置也有一个3，那么我们也可以清楚地得知送索引2后一位到索引15的和是0.

所以说，知道每一个前缀和在最左边第一次出现的位置是至关重要的，因为后面每当出现同样的前缀和，两次的索引相减+1之后得到的，就可能是目前已知的区间线段和为0的最长索引，而这两次相同前缀和之间和他们相同的前缀和的索引是多少，我们并不关心，就像我们现在有最左边的前缀和为3的索引是2，目前找到前缀和为3的索引是15，那么我们就不会关心中间前缀和为3的索引5了，因为无论如何他都不可能最长。

所以我们要建立一个结构去存储最左边第一次出现前缀和为sum[i]时候的索引。每次出现相同前缀和，我们就判断一下是不是可能为最长的。同时注意特殊情况，因为当前缀和为0的时候，假设sum[i]为0，那么一定有一种默认情况出现，也就是从0~i这些位置的和也是0，最长的子区间有可能是【0，i】.

```
class Solution {
public:
	vector<int> cntbias;
	vector<string> findLongestSubarray(vector<string>& array) {
		
		for (int i = 0; i < array.size(); i++){
			cntbias.push_back(cntb(array[i]));
		}
		
		//sum[i]表示从0到i的前缀和
		vector<int> sum;
		sum.push_back(cntbias[0]);
		int cntsum = cntbias[0];
		for (int i = 1; i < cntbias.size(); i++){
			cntsum += cntbias[i];
			sum.push_back(cntsum);
		}
		int start = -1;
		int end = -1;
		int maxLength = 0;
		unordered_map<int, int> mp;//mp[k] = index表示出现和为k的最左边索引为index
		for (int i = 0; i < sum.size(); i++){
			if (mp.find(sum[i]) != mp.end()){//最左边出现过
 
				if (sum[i] == 0){//和为0的情况特殊，因为当某一个index为i的时候，最长的子线段长度一定是0~i，也就是长度为i+1
					if (i + 1 > maxLength){
						maxLength = i + 1;
						start = 0;
						end = i;
					}
				}
				else{
					if (i - mp[sum[i]] > maxLength){
						maxLength = i - mp[sum[i]];
						start = mp[sum[i]] + 1;
						end = i;
					}
				}
			}
			else { 
				//前缀和为sum[i]第一次出现，记录下来
				mp.insert(make_pair(sum[i], i));
				//这里需要注意哪怕是第一次出现0也需要比较，这和前缀和为其他的不一样
				if (sum[i] == 0){
					if(i + 1 > maxLength){
						maxLength = i + 1;
						start = 0;
						end = i;
					}
				}
			}
		}
		if (start == -1) return{};//没有找到前缀和为0的
		vector<string> ret(array.begin() + start, array.begin() + end + 1);
		return ret;
	}
 
	//判断这个字符串是数字字符串还是字母字符串
	int cntb(string s){
		if (s[0] >= '0' && s[0] <= '9') return 1;
		return -1;
	}
};
```
