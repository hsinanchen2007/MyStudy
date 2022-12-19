### 解题思路
map+滑动窗口

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int n = s.size();
        vector<int> m(128,0);
        int i=0,j=0;
        while(j<n&&i<n){
            if(m[s[j]]<1&&j<n){
                m[s[j]]++;
                j++;
            }else{
                m[s[i]]--;
                i++;
            }
            res = max(res,j-i);
        }
        return res;
    }
};
```

### 代码2
上述的方法最多需要执行 2n 个步骤。事实上，它可以被进一步优化为仅需要 n 个步骤。我们可以定义字符到索引的映射，而不是使用集合来判断一个字符是否存在。 当我们找到重复的字符时，我们可以立即跳过该窗口。

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), res = 0;
        vector<int> index(128,0); // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            i = max(index[s[j]], i);
            res = max(res, j - i + 1);
            index[s[j]] = j + 1;
        }
        return res;
    }
};
```
