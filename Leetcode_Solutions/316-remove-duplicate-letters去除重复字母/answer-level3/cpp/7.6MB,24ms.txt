### 解题思路
内存消耗击败100%，执行用时24ms,不是很好

### 代码

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> alp(26, 0);
        vector<pair<int, int>> idx;
        for(int i = 0; i < s.size(); ++i){
            if(!alp[s[i] - 'a']) {
                idx.push_back(pair<int, int>(s[i] - 'a', i));
            }
            alp[s[i] - 'a']++;
        }
        sort(idx.begin(), idx.end(), [=](pair<int, int> p1, pair<int, int> p2){
            return p1.first < p2.first;
        });
        string res = "";
        for(auto it : idx){
            char a = 'a' + it.first;
            if(iter(0, it.second, string(1, a),  res, alp, s, idx.size()))  break;
        }   
        return res;
    }

    bool iter(int begin, int end, string cur, string& res, vector<int> alp, string& s, int size){
        //cout << cur << " ";
        if(size == cur.size()){
            res = cur;
            return true;
        }
        for(int i = begin; i < end; ++i){
            if(alp[s[i] - 'a']){
                if(alp[s[i] - 'a'] == 1){
                    return false;
                }
                alp[s[i] - 'a']--;
            }
        }
        char a = s[end];
        alp[a - 'a'] = 0;
        for(int i = 0; i < 26; ++i){
            if(alp[i]){
                a = 'a' + i;
                //cout << a << " ";
                int idx = -1;
                for(int j = end + 1; j < s.size(); ++j){
                    if(s[j] == a){
                        idx = j;
                        break;
                    }
                }
                if(iter(end + 1, idx, cur + string(1, s[idx]), res, alp, s, size)){
                    return true;
                }
            }
        }
        return false;
    }
};
```