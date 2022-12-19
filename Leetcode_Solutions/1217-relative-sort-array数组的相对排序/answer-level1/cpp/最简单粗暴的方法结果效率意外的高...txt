

执行用时 :4 ms, 在所有 C++ 提交中击败了97.96%的用户
内存消耗 :8.8 MB, 在所有 C++ 提交中击败了100.00%的用户
```
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        int pool[1001] = {0};
        vector<int> output;
        
        for(int i=0; i<arr1.size(); i++){
            
            pool[arr1[i]]++;
        }
        
        for(int i=0; i<arr2.size(); i++){
            
            for(int j=0; j<pool[arr2[i]]; j++){
                
                output.push_back(arr2[i]);
            }
            
            pool[arr2[i]] = 0;
        }
        
        for(int i=0; i<1001; i++){
            
            while(pool[i]-->0){
                
                output.push_back(i);
            }
        }
        
        
        return output;
    }
};
```
