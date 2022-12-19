### 解题思路
此处撰写解题思路
1.queue 中加入的一定是可以打开的，见过一些数组来表示queue，一个begin，一个end，begin = end 表示结束，这里有表明最大的box数量是1000；
2.辅助数据 hasVisit，如果已经访问过，在加入queue的时候，设置访问过；
3.如果有钥匙，不要一个辅助数据才纪录，直接改变status的数据；
4.hasBox 表明有是否拥有box。
### 代码

```cpp
class Solution {
public:
  int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue <int> q;
        //vector <bool> hasKey; hasKey.resize(status.size() , false);
        vector <bool> hasBox; hasBox.resize(status.size() , false);
        vector <bool> hasVisit; hasVisit.resize(status.size() , false);
        int ans = 0 ;
        for (unsigned int i = 0 ; i < initialBoxes.size() ; ++i)
        {
            if ( status[initialBoxes[i]] == 1)
            {
                q.push(initialBoxes[i]);
                hasVisit[initialBoxes[i]] = true;
            }
            else
            {
                hasBox[initialBoxes[i]] = true; 
            }
        }

        while( !q.empty())
        {
            int currentBox = q.front();
            q.pop();
    
            hasVisit[currentBox] = true;
            ans+= candies[currentBox];
            vector <int> curKey = keys[currentBox];
            vector <int> curContainBox = containedBoxes[currentBox];
            for (int c : curContainBox)
            {
                if ( (/*hasKey[c] ||*/ status[c] == 1) && !hasVisit[c])
                {
                    q.push(c);
                    hasVisit[c] = true;
                }
                else
                {
                    hasBox[c] = true;
                }
            }
            for (int c : curKey)
            {
                if ( hasBox[c] && !hasVisit[c])
                {
                    q.push(c);
                    hasVisit[c] = true ;
                }
                else
                {
                    //hasKey[c] = true ;
                    status[c] = 1;
                }
            }
        }
        return ans;
    }  
};
```