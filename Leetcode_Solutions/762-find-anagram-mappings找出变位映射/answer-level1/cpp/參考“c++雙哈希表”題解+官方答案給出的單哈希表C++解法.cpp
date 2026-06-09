### 解题思路
1. 用一個哈希表映射B中元素和下標
2. 因爲A中元素和B中相同，則經過mapB映射后可得到對應下標，遍歷A即可得到答案
代碼如下
### 代码

```cpp
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int,int> mapB;
        vector<int> ans;
        int iter = 0;
        for(auto b:B)
            mapB[b] = iter++;//存儲B中元素對應的下標

        for(int i = 0;i<A.size();i++)
        {
           ans.push_back(mapB[A[i]]);//映射得到對應答案
        }
        return ans;
    }
};

```