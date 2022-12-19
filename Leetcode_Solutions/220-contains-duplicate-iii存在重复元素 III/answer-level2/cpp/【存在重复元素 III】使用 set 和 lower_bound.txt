### 思路
详细可以查看 [官方题解](https://pic.leetcode-cn.com/bb19331ac3fc5c03ad5b475d86b8235df91d2b697173c3dc5e5535874bc6ecb8) 的 **方法二 （二叉搜索树）** 。   
但是其中给出的Java代码，并说  
> C++ 中的 std::set，std::set::upper_bound 和 std::set::lower_bound 分别等价于 Java 中的 TreeSet，TreeSet::ceiling 和 TreeSet::floor。

这句是不准确的。  

简单的说，  

std::set::upper_bound 是 >  
std::set::lower_bound 是 >=  

修改和调整之后，通过了测试。  


### 答题
```C++
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
{
	set<double> _set;
	for (int i = 0; i < nums.size(); ++i) 
	{
		auto s = _set.lower_bound((double)nums[i] - (double)t);
		if (s != _set.end() && *s <= (double)nums[i] + (double)t) 
		{
			return true;
		}

		_set.insert(nums[i]);
		if (_set.size() > k) 
		{
			_set.erase(nums[i - k]);
		}
	}
	return false;
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)