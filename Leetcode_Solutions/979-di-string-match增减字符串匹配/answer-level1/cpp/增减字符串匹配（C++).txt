### 题目理解：
本题的意思为：根据输入的字符串序列$S$，输出一个符合要求的数字序列，该输出数字序列有$N=S.length()$个元素，且元素来自集合$\phi=[0,1,2,\cdots,N]$中。根据题目的举例，我们不难发现，根据如下规则输出的数字序列一定是符合要求的：

- 当$S[i]=I$时，我们将集合$\phi$最左侧的元素填入数字序列，并将该元素移出集合$\phi$
- 当$S[i]=D$时，我们将集合$\phi$最右侧的元素填入数字序列，并将该元素移出集合$\phi$

### 代码：

```c++
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        int left = 0, right = S.length();
        for(int i = 0; i < S.length(); ++i)
        {
            if(S[i] == 'I')
                ans.push_back(left++);
            if(S[i] == 'D')
                ans.push_back(right--);
        }
        ans.push_back(left);
        return ans;
    }
};
```

### 复杂度分析：
**时间复杂度：** 遍历了整个字符串$S$，故时间复杂度为$O(n)$
**空间复杂度：** 创建了一个vector保存结果，故空间复杂度为$O(n)$
