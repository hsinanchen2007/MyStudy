### 解题思路
简单直接的思路。
比如[2,1,3,3,3,2]，碰到第一个是2，那么某个用户组肯定有2个人，那么就先把用户0存储起来。
接着碰到1，那么只有一个用户，也就是用户1，加入到要返回的vector中。
接着碰到3，这个用户组有3个用户，包含用户2，先把用户2存起来。
接着碰到3，可以加入到之前包含3个用户的用户组中，存储起用户3。
接着碰到3，可以加入到之前包含3个用户的用户组中，存储起用户4。
然后发现包含3个用户的用户组已经满了，可以加入到要返回的vector中。
最后碰到2，可以加入到之前包含2个用户的用户组中，存储起用户5。
然后发现包含2个用户的用户组已经满了，可以加入到要返回的vector中。

整个思路非常直接。本题使用了map<int,vector<int>>来存储中间结果，但其实使用vector<vector<int>>来存储也是OK的，特别是本题有给出n的范围，可以依此限定一下二维vector的size。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        map<int,vector<int>>m1;
        vector<vector<int>>res;
        for(int i=0;i<groupSizes.size();i++)
        {
            m1[groupSizes[i]].push_back(i);
            if(m1[groupSizes[i]].size()==groupSizes[i])
            {
                res.push_back(m1[groupSizes[i]]);
                m1[groupSizes[i]]={};
            }
        }
        return res;
        
    }
};
```