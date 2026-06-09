### 解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
6.1 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int flag[256]={0};
        for(int i=0;i<S.length();i++){
            flag[S[i]]++;
        }
        int count=0;
        for(int i=0;i<J.length();i++){
            count+=flag[J[i]];
        }
        return count;

    }
};
```