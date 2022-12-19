### 解题思路
此题运用滑动窗口思想，设置两个整形变量l和r，初始值为0和-1（这样设置是让初始区间不包含元素）

### 代码

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int l=0,r=-1;
    	int sum=0;
    	int res=nums.size()+1;
    	while(l<nums.size()){
    		if(r+1<nums.size() && sum<s){
    			r++;
    			sum+=nums[r]; 
			}
			else{
				sum-=nums[l];
				l++;
			}
			if(sum>=s)
				res=min(res,r-l+1);
		}
		if(res==nums.size()+1)
			return 0;
		return res;

    }
};

```