执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8 MB
, 在所有 C++ 提交中击败了
91.80%
的用户
```c++ []
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int cnt = 0;
        while(z){
            if(z & 1) ++cnt;
            z = z >> 1;
        }
        return cnt;
    }
};
```