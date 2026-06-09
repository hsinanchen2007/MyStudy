### 解题思路
### 代码

```cpp
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        map<set<int>,int> map1;
        int count=0;
        for(int i=0;i<dominoes.size();i++)
        {
            set<int> set1;
            set1.insert(dominoes[i][0]);
            set1.insert(dominoes[i][1]);
            map1[set1]++;
        }
        map<set<int>,int>::iterator it;
        for(it = map1.begin();it != map1.end();it++)
        {
            if(it->second >1) count  += (it->second)*(it->second - 1)/2;
        }
        return count;

    }
};
```