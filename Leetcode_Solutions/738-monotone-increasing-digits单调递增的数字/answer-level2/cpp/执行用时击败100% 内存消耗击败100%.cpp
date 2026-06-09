### 解题思路
1 先用index记录前面可以保留的位数
2 在把后面的使用9填充即可


### 代码

```cpp
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
    	if (N < 10) return N;
    	string nums = to_string(N);

    	int index = -1;
    	for (int i = 0; i < nums.size() - 1; ++i) {
    		if (nums[i] < nums[i+1]) index = i;
    		else if (nums[i] > nums[i+1]) break;
    	}

    	if (index == nums.size() - 2) return N;

    	if (index == -1) {
    		string tmp = "";
    		if (nums[0] != '1') tmp += nums[0] - 1;
    		for (int i = 1; i < nums.size(); ++i) tmp += '9';
    		return atoi(tmp.c_str()); 
    	}

    	string tmp = nums.substr(0, index+1);
    	tmp += nums[index+1] - 1;
    	for (int i = index + 2; i < nums.size(); ++i) tmp += '9'; 
    	return atoi(tmp.c_str()); 
    }
};	
```