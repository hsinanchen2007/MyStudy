### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        deque<int> temp;
        if(A.size()==0)return {};
        for(auto n:A)
        {
            if(n%2==0)temp.push_front(n);
            else temp.push_back(n);
        }
        return vector<int>(temp.begin(),temp.end());
    }
};
```