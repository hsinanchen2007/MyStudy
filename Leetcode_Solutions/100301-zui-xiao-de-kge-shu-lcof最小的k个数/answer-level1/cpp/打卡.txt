### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int>res;
		sort(arr.begin(),arr.end());
		for(int i=0;i<arr.size()&&i<k;i++)
			res.push_back(arr[i]);
		return res;
    }
};
```