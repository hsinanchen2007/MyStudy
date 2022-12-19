first[],last[]保存每个数所在连续正整数的左右端点，复杂度O(len(nums))
```
#include<vector>
#include<cstring>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int first[len + 2];
        int last[len + 2];
        memset(first,-1,sizeof first);
        memset(last,-1,sizeof last);
        for(int i = 0;i < len;++i){
        	int temp = nums[i];
        	if(temp <= 0 || temp > len || first[temp] != -1)continue;
			if(first[temp - 1] == -1){
				last[temp - 1] = temp;
				first[temp] = temp - 1;
			}
			else{
				last[first[temp - 1]] = temp;
				first[temp] = first[temp - 1];
			}
		}
		int ret = 0;
		while(last[ret] != -1)ret =last[ret];
		return ret + 1;
    }
};
```