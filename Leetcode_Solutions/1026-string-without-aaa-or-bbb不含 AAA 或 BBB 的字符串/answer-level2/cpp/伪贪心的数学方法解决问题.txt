### 解题思路
本题应该是应用贪心的思路，但是由于题目保证解一定存在，最后代码不需要按照贪心算法去写，简单演算一下就能得到如下的解法。

不妨设A >= B，令t = A - B，显然有A - 2t = B - t，将 A - 2t 记为 m
一个显然正确的策略是：先写入t个“aab”,然后写入m个“ab”。
我们需要重点思考的是边界情况是什么样的。
- 如果m >= 0，此时能直接得到正确结果
- 如果m < 0，我们可以简单验证出：
1. m < -2，此时无解，而题目已经保证了这种情况不会出现
2. -2 <= m < 0，这时候从尾部弹出多出来的1对或者2对"ab"/"ba"即可。

##### 
##### 执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
##### 内存消耗 : 6.1 MB , 在所有 C++ 提交中击败了 100.00% 的用户

### 代码

```cpp
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string str;
        string aab = "aab";
        str.reserve(A + B + 5);

        if(A < B)
        {
            swap(A, B);
            aab = "bba";
        }

        int t = A - B;
        A -= 2 * t;
        B -= t;
        while(t--) str += aab;

        if(A < 0) while(A++) {str.pop_back(); str.pop_back();}
        else while(A--) str += "ab";

        return str;
    }
};
```