### 解题思路
双百，同样的操作做两次，helper封装操作，调用两次就行。

### 代码

```cpp
class Solution {
public:
    void helper(vector<int>& A, vector<int>& B){
        int len=A.size();
        stack<int> s;
        for(int i=len-1;i>=0;i--){
            s.push(A[i]);
        }
        while(!s.empty()){
            B.push_back(s.top());
            s.pop();
        }
    }
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        helper(A,B);
        helper(B,C);
    }
};
```