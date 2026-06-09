### 解题思路
* 先是暴力法逐个比较求解，为了方便理解，加了个辅助函数；
* 后来看官方解答后改用哈希法，但是耗时依然很高，可能是因为用了辅助函数多了内存消耗？后来改成不用辅助函数，发现没有改善；
* 看到耗时28ms的解答后，弃用unordered_map，改用int[]，再用到copy()函数，真有大的改善。

### 代码

* 暴力
```cpp
    int countCharacters(vector<string>& words, string chars) {
        if(words.empty() || chars.empty())   return 0;
        int ans = 0;
        for(string s: words) {
            int cnt = matchw(s, chars);
            if(cnt > 0) ans += cnt;
        }
        return ans;
    }
    int matchw(string word, string mark) {
        int cnt = 0;
        for(int i = 0; i < word.size(); i++) {
            for(int j = 0; j < mark.size(); j++) {
                if(word[i] == mark[j]) {
                    mark[j] = '\0';         
                    cnt++;
                    break;
                }
            }
        }
        if(cnt == word.size())
            return word.size();
        else return -1;
    }
```
![1.png](https://pic.leetcode-cn.com/940c34b26d32b7fce430dd282ee149513e2d0101b5af8326bcd1984e25749b30-1.png)

* 哈希

```cpp
    // 使用unordered_map
    int countCharacters(vector<string>& words, string chars) {
        if(words.empty() || chars.empty())   return 0;

        unordered_map<char, int> mark;
        unordered_map<char, int> tmp;
        for(char c: chars) {
            mark[c]++;
            tmp[c]++;
        }
        int ans = 0;
        int flag = 1;
        for(string s: words) {
            for(char c: s) {
                mark[c]--;
                if(mark[c] < 0) 
                    flag = 0;
            }
            if(flag)    ans += s.size();
            else    flag = 1;
            for(char c: chars)
                mark[c] = tmp[c];
        }
        return ans;
    }
```
![3.png](https://pic.leetcode-cn.com/56122c55c8918fa2e83a82f646e6b4b22a29e0dbba524fbbf4e7aebdf9289f74-3.png)

```cpp
// 使用int[]
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if(words.empty() || chars.empty())   return 0;

        int charlist[26]{0};
        for(char c: chars) {
            charlist[c - 'a']++;
        }
        int ans = 0;
        int flag = 1;
        for(string s: words) {
            int tmplist[26];
            copy(charlist, charlist+26, tmplist);

            for(char c: s) {
                tmplist[c - 'a']--;
                if(tmplist[c - 'a'] < 0) 
                    flag = 0;
            }
            if(flag)    ans += s.size();
            else    flag = 1;
        }
        return ans;
    }
};
```
![2.png](https://pic.leetcode-cn.com/59c8c046d715bc61635f128d5dec05d58c884e029576d569667ac7f8a7b941ac-2.png)
