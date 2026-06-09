### 解题思路
要点：vector排序+遍历（比较函数不声明为static会报错？？）
执行用时 :88 ms, 在所有 C++ 提交中击败了39.44%的用户
内存消耗 :26.2 MB, 在所有 C++ 提交中击败了21.43%的用户
### 代码

```cpp
class Solution {
public:
    static bool comp(const int &a,const int &b)
    {
        return a<b;
    }
    int minIncrementForUnique(vector<int>& A) {
        if(A.empty()){
            return 0;
        }
        int move=0;
        sort(A.begin(),A.end(),comp);
        for(int i=1;i<A.size();i++){
            if(A[i]<=A[i-1]){
                move+=A[i-1]-A[i]+1;
                A[i]+=A[i-1]-A[i]+1;
            }
        }
        return move;
    }
};
```