### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
    	if(!k)return {};
    	if(shorter == longer)return{k*shorter};
    	vector<int> ans(k+1);
    	for(int i = 0; i <= k; ++i)ans[i] = shorter*(k-i)+longer*i;
        return ans;
    }
};
