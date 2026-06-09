### 解题思路
单调队列
![image.png](https://pic.leetcode-cn.com/a1c2d3e88e6a62d31415ffba69fa943536dcf2b5ac1107d84a2a48880e97a0aa-image.png)

### 代码


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int head=1,tail=0;
        int pos[1000];
	    for(int i=0;i<nums.size();i++){
		if(head<=tail&&i-pos[head]>=k)head++;
		while(head<=tail&&nums[i]>=nums[pos[tail]]){
			tail--;
		}
		tail++;
		pos[tail]=i;
		if(i-k+1>=0)ans.push_back(nums[pos[head]]);
	}
    return ans;
    }
};
