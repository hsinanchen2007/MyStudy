![image.png](https://pic.leetcode-cn.com/61abf0f50101b1a4654d03a6469fb3fd3a9b081e2c5d4750681ea7032bea7df7-image.png)
```
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
    	int i,j,k;
    	vector<int> re;
		for(i=0,j=1;j<nums.size();i+=2,j+=2)
			for(k=0;k<nums[i];k++)
				re.push_back(nums[j]);
		return re;
    }
};
```
