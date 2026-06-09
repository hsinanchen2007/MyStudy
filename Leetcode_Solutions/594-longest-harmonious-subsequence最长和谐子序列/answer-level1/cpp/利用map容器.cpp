```
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int, int> p;
        int max_length = 0;
        for(int i = 0; i < n; ++i)
        {
            p[nums[i]]++;
        }
        for(map<int, int>::iterator it = p.begin(); it != p.end(); ++it)
        {   
            it++;
            if(it == p.end())
                break;
            it--;
            map<int, int>::iterator next = it;
            next++;
            if(next -> first - it -> first == 1)
            {
                if(max_length < next -> second + it -> second)
                    max_length = next -> second + it -> second;
            }
        }
        return max_length;
        
    }
};
```
