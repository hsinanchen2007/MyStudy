### 解题思路
![image.png](https://pic.leetcode-cn.com/c6f73b38f6e05b381828c86e8dc0ea9a2e1d31e6fc1fc519d12cce4dd765390b-image.png)

### 代码

```cpp
class Solution {
public:
    
    static bool cmp(int a,int b)
    {
        string A = "",B = "";
        A +=to_string(a);
        A +=to_string(b);
        B +=to_string(b);
        B +=to_string(a);
        return A < B;

    }

    string minNumber(vector<int>& nums) {
        string ans = "";
        int size = nums.size();
        if(size == 0) return ans;
        //把给定的数组排序
        sort(nums.begin(),nums.end(),cmp);
        for(int i = 0;i < size;i++)
        {
            ans += to_string(nums[i]);
        }
        return ans;
    }
};
```