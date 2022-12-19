![4.PNG](https://pic.leetcode-cn.com/7191d9a8924ae9c5f67a35a4815f6d4f44bf678d5ef55ab83e62647380ce85b1-4.PNG)

```
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        int x;
        for(int i=0;i<nums.size();i++){
        	x=nums[i];
        	if((x>=10&&x<=99)||(x>=1000&&x<=9999))
        		count++;
		}
		return count;
    }
};
```
