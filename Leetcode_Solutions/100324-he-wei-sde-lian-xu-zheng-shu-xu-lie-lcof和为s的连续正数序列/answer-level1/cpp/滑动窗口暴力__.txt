~~~
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>res;
        vector<int>m;
        if(target == 1) return res;
        int sum = 0;
        for(int i = 1; i <= target/2 + 1; i++)
        {
            m.emplace_back(i);
            sum += i;
            while(sum > target)
            {
                sum -= m[0];
                m.erase(m.begin());   
            }
            if(sum == target) res.emplace_back(m);
        }
        return res;
    }
};
~~~