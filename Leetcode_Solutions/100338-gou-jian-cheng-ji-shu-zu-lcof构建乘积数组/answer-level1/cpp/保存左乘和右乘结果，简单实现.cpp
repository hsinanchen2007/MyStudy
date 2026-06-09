```
class Solution {
public:
    vector<int> constructArr(const vector<int>& A) {
        vector<int> B;
        int length = A.size();
        if(length == 0)
            return B;
        
        int curProduct = 1;
        for(int i = 0; i < length; i++){
            if(i == 0){
                B.push_back(curProduct);
                curProduct *= A[i];
                continue;
            }
            
            B.push_back(curProduct);
            curProduct *= A[i];
        }
        
        curProduct = 1;
        for(int i = length-1; i >= 0; i--){
            if(i == length-1){
                curProduct *= A[i];
                continue;
            }
            
            B[i] *= curProduct;
            curProduct *= A[i];
        }
        
        return B;
    }
    
};
```
