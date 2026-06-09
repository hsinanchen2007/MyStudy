### 解题思路
![image.png](https://pic.leetcode-cn.com/785e5a8ce47cca7eccd9b322a1404ff79bec3a044571a8d6cd43d92637c57630-image.png)
观察可发现，下一层的第k处（从0开始计算）的字符与本层与其对应的字符有关，本层字符+k，如果是偶数的话k处为0，奇数的话k处为1.

### 代码

```cpp
class Solution {
public:
    int kthGrammar(int N, int K) {
        vector<int> ans;
        int start = 0;
        if(N == 1)  //第一层直接输出
        return 0;
        int k = K - 1;  //题目中的K指的是从1开始计数
        while(N >= 2)
        {
            ans.push_back(k);  //记录所要求的字符是由每一行的k处产生的
            k = k / 2;
            N --;
        }
        for(int i = ans.size() - 1; i >= 0; i --)
        {
             start = (start + ans[i]) % 2 == 0 ? 0 : 1;
        }
        return start;
    }
};
```