```
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> forend(arr1.size(),0);
        map<int,int> maparr1;
        for(int j = 0; j < arr1.size(); ++j) {
            if(maparr1.find(arr1[j]) != maparr1.end()){
                maparr1[arr1[j]]++;
            } else {
                maparr1.insert(map<int, int>:: value_type(arr1[j], 1));
            }
        }
        int before = 0;
        int front = arr1.size() - 1;
        for(int i = 0; i < arr2.size(); ++i) {
            if(maparr1.find(arr2[i]) != maparr1.end()) {
                for(int k = 0; k < maparr1[arr2[i]]; ++k) {
                    forend[before] = arr2[i];
                    before++;
                }
                maparr1.erase(arr2[i]);
            } 
        }
        

        for(auto it = maparr1.begin(); it !=  maparr1.end(); ++it) {
            for(int k = 0; k < it->second; ++k){
                forend[before] = it->first;
                before++;
            }

        }

        return forend;
    }
};
```
![image.png](https://pic.leetcode-cn.com/1211229410544c611c11fafe07181dfd59aab55b17c4810f3a4ad9279fb90075-image.png)
