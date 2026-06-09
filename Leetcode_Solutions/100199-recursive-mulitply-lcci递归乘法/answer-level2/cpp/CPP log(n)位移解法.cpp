### 解题思路
1. 理论上，这个解法直接循环也行。但是，题目要求了递归，那就得按递归处理。
2. 测试用例样本比较小，所以，其实直接不断multiply(A, B-1) + A就可以解决。但是需要处理min(m+n)次
3. 使用位移的方法，每次把问题缩小到一半。位移其实就等于*2 /2，所以考虑下乘除的时候，用不用考虑个单独的1就行了 

### 代码

```cpp
class Solution {
public:
    int multiply(int A, int B) {
        if (A < B) {
            return multiply(B, A);
        }

        if (A==0 || B == 0) {
            return 0;
        }

        int num = multiply(A<<1, B>>1);
        if (B&1 == 1) {            
            return num + A;
        } else {            
            return num;
        }
    }
};
```