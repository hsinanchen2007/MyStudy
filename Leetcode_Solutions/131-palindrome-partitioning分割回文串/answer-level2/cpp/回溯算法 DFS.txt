### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool verifyString(string s){
      int left = 0, right = s.size() - 1;

      while(left <= right){
        if(s[left] != s[right])
          return false;
        left++;
        right--;
      }
      return true;
    }

    void dfs(vector<vector<string>>& res, vector<string>& tmp, string s, int idx){
      if(idx == s.size()){
        res.push_back(tmp);
        return;
      }
      //i表示字符串长度，start是从idx开始的，长度的区间是1~s.size() - idx
      for(int i = 1; i <= s.size() - idx; i++){
        string tmpS = s.substr(idx, i);
        if(verifyString(tmpS)){
          tmp.push_back(tmpS);
          //下一个起点是，上一个start+长度
          dfs(res, tmp, s, idx + i);
          tmp.pop_back();
        }
      }
    }

    vector<vector<string>> partition(string s) {
      vector<vector<string>> res;
      if(s.size() == 0) return res;

      vector<string> tmp;
      dfs(res, tmp, s, 0);

      return res;
    }
};
```