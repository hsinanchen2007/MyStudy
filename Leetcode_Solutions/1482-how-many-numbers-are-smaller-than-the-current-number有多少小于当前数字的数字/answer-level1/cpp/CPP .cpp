### 解题思路
先排序, 就简单了
![image.png](https://pic.leetcode-cn.com/b63ac48a7c45b4a88217f11f489665d2b08761a017f951771dcd2e876f3e768c-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        auto vec = nums;
	sort( vec.begin( ), vec.end( ) );
	vector<int> ret;
	for(auto& value : nums){
		auto index = std::find( vec.begin( ), vec.end( ), value );
		ret.push_back( index - vec.begin( ) );
	}
	return ret;

    }
};
```