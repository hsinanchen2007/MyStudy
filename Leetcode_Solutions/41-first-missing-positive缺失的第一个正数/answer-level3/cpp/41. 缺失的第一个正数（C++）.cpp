# 41. 缺失的第一个正数
先排序，再循环好最小的正数
```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp = 1;
        for( int i = 0; i < nums.size(); ++i ){
        	if( nums[i] <= 0 )
        		continue;
        	if( temp == nums[i] )
        		++temp;
        	else if( temp < nums[i] )
        		break;
        }
    	return temp;
    }
};
```
