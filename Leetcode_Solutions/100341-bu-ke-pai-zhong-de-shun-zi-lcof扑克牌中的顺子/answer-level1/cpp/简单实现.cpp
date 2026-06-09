```
class Solution {
public:
    bool isStraight(vector<int> data) {
        int length = data.size();
        if(length == 0)
            return false;
        
        int numOfKing = 0;
        for(int i = 0; i < length; i++){
            if(data[i] == 0)
                numOfKing++;
        }
        
        sort(data.begin(), data.end());
        
        int mBegin = 0;
        for(; mBegin < length; mBegin++){
            if(data[mBegin] != 0)
                break;
        }
        if(mBegin == length)
            return true;
        
        int numOfGap = 0;
        int mEnd = mBegin + 1;
        while(mEnd <= length-1){
            if(data[mBegin] == data[mEnd])  // 注意有对子就不可能是顺子
                return false;
            numOfGap += (data[mEnd] - data[mBegin] - 1);
            mBegin++;
            mEnd++;
        }
        
        if(numOfGap <= numOfKing)
            return true;
        else
            return false;
    }
    
};
```
