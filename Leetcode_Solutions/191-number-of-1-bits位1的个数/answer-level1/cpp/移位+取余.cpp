执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了5.21%的用户

```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int k=32;
        int res=0;
        while(k){
            if(n%2==1) res++;
            n>>=1;
            k--;
        }
        return res;
    }
};
```
