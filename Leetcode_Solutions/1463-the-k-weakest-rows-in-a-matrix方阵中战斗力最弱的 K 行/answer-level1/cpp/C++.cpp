对每一行求和,所得的结果作为键值,行号作为值.
由于键值可能相同,故采用multimap
键值小,战斗力弱
键值相同时,行号小的在前,符合题意
所以将map中前k个元素的值(即为行号),放入最终结果的vector中

参考代码如下:
```
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> ans;
        multimap<int, int>m;
        for(int i = 0; i < row; ++i)
        {
            int sum = 0;
            for(int j = 0; j < col; ++j)
            {
                sum += mat[i][j]; 
            }
            m.insert(make_pair(sum, i));
        }
        for(auto &t : m)
        {
            if(ans.size() < k)
                ans.push_back(t.second);
        }
        return ans;
    }
};
```
![image.png](https://pic.leetcode-cn.com/57ba6db6d98a1ede09e2062cf39ea090c6ed6666d5299dadf0536bcf52ceb575-image.png)
