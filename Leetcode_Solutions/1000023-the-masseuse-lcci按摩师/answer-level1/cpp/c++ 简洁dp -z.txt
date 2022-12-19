### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) { 
        int n = nums.size();
        if(n == 0)    return 0;
        if(n == 1)    return nums[0];

        vector<int> d(n);
        d[0] = nums[0];
        d[1] = max (nums[0], nums[1]);

        for (int i = 2; i < n; i++) 
            d[i] = max(d[i-2] + nums[i], d[i-1]);
        
        return d[n-1];
    }
};

```

### 优化

```cpp
class Solution {
public:
    int massage(vector<int>& nums) { 
        int pre = 0, cur = 0;
        for (int n : nums) 
        {
            int temp = max(pre + n, cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};

```

