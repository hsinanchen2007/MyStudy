### 解题思路
小细节还是蛮多的，需要小心

### 代码

```cpp
class Solution {
public:
    bool isVaild(string s){
      if((s.size() > 1 && s[0] == '0') || stoi(s) > 255)
        return false;
      return true;
    }

    void dfs(string s, vector<string>& res, vector<string>& tmp, int pos){
      //如果出现后面的字符比3 * size还要大，就不需要搜索了
      if(s.size() - pos > 3 * (4 - tmp.size())){
        return;
      }

      if(tmp.size() == 4 && pos == s.size()){
        string tmpString;
        for(int i = 0; i < 4; i++){
          tmpString = tmpString + tmp[i];
          if(i != 3)
            tmpString += '.';
        }
        res.push_back(tmpString);
        return;
      }

      for(int i = pos; i < s.size() && i < pos + 3; i++){
        string ip = s.substr(pos, i - pos + 1);
        if(isVaild(ip)){
          tmp.push_back(ip);
          dfs(s, res, tmp, i + 1);
          tmp.pop_back();      
        }
      }
    }

    vector<string> restoreIpAddresses(string s) {
      vector<string> res;
      vector<string> tmp;
      if(s.size() < 4)  return res;
      dfs(s, res, tmp, 0);
      return res;   
    }
};
```