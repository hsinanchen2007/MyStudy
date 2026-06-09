### 解题思路
1. 将开始字符`ch`设置为`S[0]`，从下标`1`开始遍历字符串`S`
2. 若当前第`i`位和`ch`相同，则增加`ch`的计数
3. 若不同，压缩前面遍历得到字符串和计数，如`sss`压缩成`s3`，加入到结果字符串`ans`中
4. 继续遍历，直到压缩完字符串`S`
5. 返回`ans`和`S`中长度较小的那个字符串

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        char ch = S[0];
        int cnt = 1;
        string ans = "";
        for(int i = 1; i < S.size(); i++){
            if(S[i] == ch){
                cnt++;
            }
            else{
                ans += ch; ans += to_string(cnt);
                ch = S[i];
                cnt = 1;
            }
        }
        ans += ch; ans += to_string(cnt);
        if(ans.size() >= S.size()) return S;
        else return ans;
    }
};
```