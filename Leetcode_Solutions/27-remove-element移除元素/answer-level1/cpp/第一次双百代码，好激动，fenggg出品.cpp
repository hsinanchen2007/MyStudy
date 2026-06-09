### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (vector<int>::iterator i = nums.begin(); i != nums.end();) {
		if (*i == val) {
			i=nums.erase(i);
		}
		else {
			i++;
		}
		
	}
	return nums.size();
    }
};
```