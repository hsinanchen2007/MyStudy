dp
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size())  return 0;
        vector<int> res(nums.size(), 1);
        int maxlen = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[i] > nums[j])
                    res[i] = max(res[i], res[j] + 1);
            }
            maxlen = max(maxlen, res[i]);
        }
        return maxlen;
    }
};
```
进行优化：
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tail(n + 1, 0);
        int k = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(k == 0 || nums[i] > tail[k])
            {
                tail[k + 1] = nums[i];
                k++;
                continue;
            }

            int l = 1, r = k;
            while(l < r)
            {
                int mid = (l + r + 1) >> 1;
                if(tail[mid] >= nums[i])
                    r = mid - 1;
                else
                    l = mid;
            }
            if(tail[r] < nums[i])
                tail[r + 1] = min(tail[r + 1], nums[i]);//要找的就是小于它的一个数
            else
                tail[r] = nums[i];//如果根本找不到呢
        }
        cout << k << endl;
        return k;
    }
};
```

