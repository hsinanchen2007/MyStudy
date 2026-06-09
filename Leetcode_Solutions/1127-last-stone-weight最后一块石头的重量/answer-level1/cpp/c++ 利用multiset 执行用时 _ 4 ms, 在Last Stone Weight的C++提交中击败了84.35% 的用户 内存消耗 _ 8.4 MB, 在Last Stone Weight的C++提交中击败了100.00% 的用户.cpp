思路很简单，每次拿最大的2个相减，有余的话重新插入multiset中，然后删掉已经处理的2个数
```
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
          multiset<int,greater<int>> tmpStones(stones.begin(),stones.end());
        
        multiset<int,greater<int>>::iterator preIt;
        multiset<int,greater<int>>::iterator curIt;
        
        while(tmpStones.size() > 1)
        {
            preIt = tmpStones.begin();
            
            if(preIt != tmpStones.end())
                curIt = ++tmpStones.begin();
            
            if(*preIt - *curIt != 0)
            {
                tmpStones.insert(*preIt - *curIt);
            }
            tmpStones.erase(preIt);
            tmpStones.erase(curIt);
        }
        
        return tmpStones.begin() != tmpStones.end() ? *(tmpStones.begin()) : 0;
    }
};
```