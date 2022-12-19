### 解题思路
"I  D  I  D"
[0, 4, 1, 3, 2]
通过观察 我们可以发现 最终输出的数组都会比输入的字符串长度 + 1
I 所对应的输出 位置可以组成一个递增序列   
D 所对应的输出 位置可以组成一个递减序列
而最后一个元素则是 l将两个序列组成的中间值

所以定义一个 max = S.size()  min = 0;
每一次遇到 I 就将对应位置 置入 min 的值 ++min
每一次遇到 D 九江队长位置 置入 max 的值 --max
最后一个的值就为 max 或者 min(因为两者已经相等)


### 代码

```cpp
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int len = S.size();
        vector<int> fin(len + 1, 0);
        int max = len, min = 0;
        int i = 0;
        for(i = 0; i < len; ++i)
        {
            if(S[i] == 'I')
                {
                    fin[i] = min;
                    ++min;
                }
            if(S[i] == 'D')
            {
                fin[i] = max;
                --max;
            }
        }
        fin[i] = max;
        return fin;
    }
};
```