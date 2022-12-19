![image.png](https://pic.leetcode-cn.com/9a5250379bbc55584be9d27e6aa74ed49af46f80b231490d25e941db5e9643f2-image.png)

```
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(!nums.size())    return res;
        int pp, p, c;
        string temp;
        for(int i = 0, j; i < nums.size(); i++){
            temp = "";
            pp = nums[i];
            p = nums[i];
            for(j = i+1; j < nums.size(); j++){
                if(p + 1 != nums[j]){
                    if(pp != p)
                        temp += (to_string(pp) + "->" + to_string(p));
                    if(pp == p)
                        temp += to_string(pp);
                    res.push_back(temp);
                    break;
                }
                p = nums[j];
            }
            i = j-1;
        }
        if(pp != p)
            temp += (to_string(pp) + "->" + to_string(p));
        if(pp == p)
            temp += to_string(pp);
        res.push_back(temp);
        return res;
    }
};
```
