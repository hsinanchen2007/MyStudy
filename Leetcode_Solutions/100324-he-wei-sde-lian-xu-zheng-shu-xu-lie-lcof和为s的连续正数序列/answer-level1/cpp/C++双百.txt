### 解题思路
此处撰写解题思路

### 代码
![1.png](https://pic.leetcode-cn.com/6856e2b4b41b48dcc5914eb2f3b35ae808ac596318f49342eff837305dade9da-1.png)

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> t;
        for(int l=1,r=2;l<r;){
            int s = (l+r)*(r-l+1)/2;
            if(s == target){
                t.clear();
                for(int i=l;i<=r;i++){
                    t.emplace_back(i);
                }
                res.emplace_back(t);
                l++;
            }
            else if(s>target)
                l++;
            else    
                r++;
        }
        return res;
    }
};
```