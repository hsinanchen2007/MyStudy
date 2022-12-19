### 思路
1，两次遍历：第一次遍历将偶数提取出来，第二次遍历将奇数提取出来；
2，原地交换：不用创建新的容器，从两头向中间同时遍历，如果左边是奇数右边是偶数就交换位置，如果左边是偶数则左边继续向右遍历，如果邮编是奇数则右边继续向左遍历，直到两边的遍历在中间相遇。
### 头文件
#include <vector>

### 代码

```两次遍历 []
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans;        
        for (auto itr=A.begin(); itr!=A.end(); itr++) 
            if (*itr%2 == 0) 
                ans.push_back(*itr);               
        for (auto itr=A.begin(); itr!=A.end(); itr++) 
            if (*itr%2 != 0) 
                ans.push_back(*itr);
        return ans;
    }
};
```
```原地交换 []
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0, j=A.size()-1;
        while(j>=i) {
            if (A[i]%2 == 0)
                i++;
            if (A[j]%2 == 1)
                j--;
            if (A[i]%2==1 && A[j]%2==0) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        return A;
    }
};
```

