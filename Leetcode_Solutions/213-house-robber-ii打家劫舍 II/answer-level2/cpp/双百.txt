### 解题思路
不看答案就没思路啊，想不到状态转移，想不到分两次偷

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n)
        {
            return 0;
        }
        if(n==1)
        {
            return nums[0];
        }
        int pre0 = 0;
        int cur0 = 0;
        func(nums,pre0,cur0,0,n-1);
        int pre1 = 0;
        int cur1 = 0;
        func(nums,pre1,cur1,1,n);
        return max(cur0,cur1);

    }
   
    
    void func( vector<int>& nums,int &pre,int &cur,int start,int end)
    {
         for(int i = start;i<end;++i)
        {
            int temp = cur;
            cur = max(pre + nums[i],cur);
            pre = temp;
        }
        
    }
};
```