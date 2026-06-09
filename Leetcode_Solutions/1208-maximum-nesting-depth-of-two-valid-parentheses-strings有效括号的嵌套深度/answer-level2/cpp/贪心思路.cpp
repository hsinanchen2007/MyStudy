### 解题思路

1.模拟两个计数器，当左括号出现时，优先进入计数器小的，当右括号出现时，优先消除计数器大的。
2.最终可以保证两个有效括号序列差异最小，那么深度最大值也最小。

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int A = 0; 
        int B = 0;
        for (int i = 0; i < seq.size(); i ++ )
        {
            if (seq[i] == '(')
            {
                if (A >= B) 
                {
                    ans.push_back(1);
                    B ++ ;
                }
                else
                {
                    ans.push_back(0);
                    A ++ ;
                }
            }
            else
            {
                if (A > B)
                {
                    ans.push_back(0);
                    A -- ;
                }
                else 
                {
                    ans.push_back(1);
                    B -- ;
                }
            }
        }
        return ans;
    }
};
```