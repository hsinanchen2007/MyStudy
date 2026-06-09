![Screenshot from 2019-09-25 22-14-14.png](https://pic.leetcode-cn.com/15d74dbd1f10a1a5c803853f7c145e177468a0acb8649e1cb00333599d7352b4-Screenshot%20from%202019-09-25%2022-14-14.png)


```
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int size = A.size();
        if(size == 0 || size != B.size()){
            return vector<int>();
        }
        vector<pair<int, int>> bIndex(size);
        vector<int> result(size);
        for(int i = 0; i < size; i++){
            bIndex[i] = {B[i], i};
        }
        sort(A.begin(), A.end());
        sort(bIndex.begin(), bIndex.end());
        auto it = bIndex.begin();
        auto rIt = bIndex.rbegin();
        for(int i = 0; i < size; i++){
            if(A[i] > it->first){
                result[it->second] = A[i];
                it++;
            } else{
                result[rIt->second] = A[i];
                rIt++;
            }
        }
        return result;
    }
};
```