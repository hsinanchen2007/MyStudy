

### 代码

```cpp
class Solution {
    bool judge(string t,string s){
        int lenx = s.size() / t.size();
        string temp;
        for (int i = 1; i <= lenx; ++i){
            temp+=t;
        }
        return temp == s;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        for (int i = min(len1, len2); i >= 1; --i){ // 从长度大的开始枚举
            if (len1 % i == 0 && len2 % i == 0){
                string res = str1.substr(0, i);
                if (judge(res, str1) && judge(res, str2)) 
                    return res;
            }
        }
        return "";
    }
};

```