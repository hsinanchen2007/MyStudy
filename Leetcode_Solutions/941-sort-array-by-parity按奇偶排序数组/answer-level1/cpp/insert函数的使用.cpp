
### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> A1,A2;
        for(int a:A)
            if(a%2==1) A1.push_back(a);//数组中的奇数
            else A2.push_back(a);//数组中的偶数
        A2.insert(A2.end(),A1.begin(),A1.end());
        return A2;
    }
};
```