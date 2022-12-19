### 解题思路
思路为求KMP算法的next数组，KMP算法，坑神有详细的讲解和模板，建议大家去围观学习！为坑神打call。
[https://www.bilibili.com/video/av94967070]()

![图片.png](https://pic.leetcode-cn.com/d553ec0a107084aeebb0a5a47fe39f5dc646caa7c174aab4130d7f4e1663d4f8-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
namespace KMP{
    vector<int> next;

    void build(const string& pattern){
        int n = pattern.length();
        next.resize(n + 1);
        for(int i = 0, j = next[0] = -1; i < n; next[++i] = ++j){
            while(~j && pattern[i] != pattern[j]) j = next[j];
        }
    }

    vector<int> match(const string &pattern, const string &text){
        int n = pattern.length();
        int m = text.length();
        vector<int> res;
        build(pattern);
        for(int i = 0, j = 0; i < n; i++){
            while(j > 0 && pattern[j] != text[i]) j = next[j];
            if(pattern[j] == text[i]) j++;
            if(j == n){
                res.push_back(i - n + 1);
                j = next[j];
            }
        }
        return res;
    }
};
class Solution {
public:
    string longestPrefix(string s) {
        KMP::build(s);
        return s.substr(0, KMP::next[s.length()]);

    }
};
```