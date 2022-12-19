### 解题思路
跟官方的差不多。学习了应用vector<vector<int>>。本来limit是target/2，但是看了官方的好像（target-1）/2更好一点。学习了emplace_back的用法，是直接在队列后构造对象，push_back是先构造临时对象，再复制，就没有emplace_back快。
![image.png](https://pic.leetcode-cn.com/89e569647403bd01ab3c1187fb4ba1817b116a54643ca02b3873e0c9d5952da9-image.png)
哈哈，100%


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        int limit=(target-1)/2;
        for(int i=1;i<=limit;i++)
        {
            int sum=0;
            for(int j=i;sum<target;j++)
            {
                sum+=j;
                if(sum>target)
                {
                    break;
                }
                else if(sum==target)
                {
                    res.clear();
                    for(int k=i;k<=j;k++)
                    {
                        res.emplace_back(k);
                    }
                    vec.emplace_back(res);
                }
            }
        }
        return vec;
    }
};
```