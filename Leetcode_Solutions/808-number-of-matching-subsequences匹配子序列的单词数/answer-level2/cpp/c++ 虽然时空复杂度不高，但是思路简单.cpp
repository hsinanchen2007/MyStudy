### 解题思路
时空复杂度确实不高，时间6.59% 空间5.16%  TAT...
不过思路也确实简单。
本质上是使用多维数据来减少重复遍历的问题 -- 维护一个`next[N+1, 26]`的数组，对于`next[i][j]`, 表示从`i`位置往后看到的第一个字母`(j+'a')`的位置。  

算法步骤：
```cpp
// 1. 建立next数组。为了能正确找到第一个字母，next数组的大小为N+1,next的位置i代表S中的位置(i-1)
// 2. 对于words中的每一个word：
//         word从0-word.size():
//             next从当前位置看word[i]:如果找到(next[cur][word[i]-'a']<next.size()), 那么更新next的下标cur
//                                    如果找不到，那么说明word不是S的子序列
//         如果word遍历完了，那么说明S中包含word的子序列
```

### 代码

```cpp
const int SIZE = 26;
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int N = S.size();
        if(N == 0) return 0;
        vector<vector<int>> next(N+1, vector<int>(SIZE, N+1));
        for(int i = N; i > 0; i--){
            next[i-1] = vector<int>{next[i]};
            next[i-1][S[i-1]-'a'] = i;
        }

        int counter = 0;
        for(const string &word: words){
            if(is_matched(word, next)) counter++;
        }
        return counter;
    }

    bool is_matched(const string &pat, const vector<vector<int>> &next){
        int index_s = 0;
        for(int i = 0; i < pat.size(); i++){
            index_s = next[index_s][pat[i]-'a'];
            if(index_s == next.size()) return false;
        } 
        return true;
    }
};
```