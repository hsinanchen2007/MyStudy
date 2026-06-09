### 解题思路
前缀异或:与前缀和的思想是类似的。只要看到连续子数组，先想前缀思想
异或的原理：
1.按位相同为0,不同为1
2.a^0 = a;
3.a^a = 0;
4.a^b^a = a^a^b = 0^b =b;

所以前缀异或的规律是：
prexor[i,j]:表示i到j 的异或 
prexor[i,j] = 0^prexor[i,j] 
            = prexor[0,i-1] ^ prexor[0,i-1] ^ prexor[i,j]
            = prexor[0,j] ^prexor[0,i-1] 

### 代码

```cpp
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        arr.insert(arr.begin(), 0);

        vector<int> prexor = vector<int>(arr.size(), 0);
        vector<int> result;

        for (int i = 1; i < prexor.size();i++){
            prexor[i] = prexor[i - 1] ^ arr[i];
        }

        for(auto query: queries){
            int xorvalue = prexor[query[1] + 1] ^ prexor[query[0]];
            result.push_back(xorvalue);
        }

        return result;
    }
};
```