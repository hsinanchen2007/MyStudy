### 解题思路
核心思路：认为绳子应该尽可能都拆成长度为3的段，然后判断最后剩余的分别是长度为0、1、2的情况，分别计算不同情况
执行用时 :4 ms, 在所有 C++ 提交中击败了54.47%的用户
内存消耗 :5.9 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3)return n-1;
        int a=n/3;
        int b=n%3;
        if(b==0){
            return pow(3,a);
        }
        if(b==1){
            return pow(3,a-1)*4;
        }
        return pow(3,a)*2;
    }
};
```