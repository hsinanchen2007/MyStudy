```
**class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>tritangle;
        tritangle.push_back(1);
        if(rowIndex==0){
            return tritangle;
        }
        for(int i=1;i<rowIndex+1;++i){
            tritangle.push_back(1);
            for(int j=tritangle.size()-2;j>0;--j){
                tritangle[j]=tritangle[j]+tritangle[j-1];
            }
        }
        return tritangle;
    }
};**
```
