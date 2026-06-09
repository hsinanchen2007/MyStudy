### 解题思路
当AB都为空的时候，返回true，所有要写一个专门的来判断，不知道小伙伴们有没有什么巧妙的办法融合到循环里面去

### 代码

```cpp
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.empty() && B.empty())
            return true;
        if(A.size() != B.size())
            return false;
        int size = A.size();
        for(int i = 0;i<size;i++){
            if(A[i]==B[0]){
                bool flag = true;
                for(int j = 0;j<size;j++){
                    if(A[(i+j)%size] != B[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    return true;
            }
        }
        return false;
    }
};
```