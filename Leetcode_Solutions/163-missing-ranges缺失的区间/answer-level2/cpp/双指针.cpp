### 解题思路
lower, upper的处理：加入vector两端
vector为空的处理：lower->upper || lower

### 代码

```cpp
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        vector<long> lnums(nums.begin(), nums.end());
        long llower = lower;
        long lupper = upper;
        if(lnums.size() != 0){
            if(lnums[0] != llower) lnums.insert(lnums.begin(), llower-1);
            if(lnums[lnums.size()-1] != lupper) lnums.push_back(lupper+1);
            long i = 0, j = 1;
            for(; i < lnums.size()-1; i++){
                long tmp = lnums[j] - lnums[i];
                if(tmp > 2){
                    string s = to_string(lnums[i]+1)+"->"+to_string(lnums[j]-1);
                    res.push_back(s);
                }
                if(tmp == 2){
                    string s = to_string(lnums[i]+1);
                    res.push_back(s);
                }
                j++;
            }
        }
        else{
            string s;
            if(llower != lupper) s = to_string(llower)+"->"+to_string(lupper);
            else s = to_string(llower);
            res.push_back(s);
        }
        return res;
    }
};
```