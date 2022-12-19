### 解题思路
思路：假设已经知道上一次的选择为正确选择（最大时长），则对于本次判断：
若是此次没有接受请求，上次可以接受也可以不接受，因此此次不接受的当前预约最大值为式1
若是此次接受请求，上次必不能接受，因此此次接受预约的当前最大值为式2
T(i,0)=max(T(i-1,0),T(i-1,1))
T(i,1)=T(i-1,0) + t(i)

### 代码

```cpp
class Solution {
public:
	int massage(vector<int>& nums) {
		
        if(nums.size()==0)
            return 0;
		int accept = nums[0], decline = 0;//T(i-1,1),T(i-1,0) 
		for (int i = 1; i < nums.size(); i++)
		{
			int temp1 = accept, temp2 = decline;
			decline = max(temp1, temp2);
			accept = temp2 + nums[i];
		}
		return max(accept,decline);
	}
};
```