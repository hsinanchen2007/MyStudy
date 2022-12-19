
### 栈
```cpp
class Solution {
public:
    string decodeString(string s) {
        string res="";
        int len=s.size();
        if(len==0) return res;
        if(len==1&&s[0]>='0'&&s[0]<='9') return res;
        else if(len==1) return s;

        stack<pair<int,string>> st;
        int num=0;
        for(auto c:s){
            if(isnumber(c)){     //数字计算出来
                num=10*num+(c-'0');
            }else if(c=='['){    //入栈
                st.push({num,res});
                res="";
                num=0;
            }else if(c==']'){    
                //出栈，temp.second存的是上层的字母，temp.first存的是上一层的数字；注意是上层的字母+上层次数*本层数字
                pair<int,string> temp=st.top();
                st.pop();
                res = temp.second + (temp.first==0 ? "" : repeat(res, temp.first));
            }else{               //字符串计算出来
                res+=c;
            }
        }
        return res;
    }
    bool isnumber(char a){
        if(a<='9'&&a>='0') return true;
        else return false;
    }
    string repeat(string &res, int num){
        string repeatres="";
        while(num>0){
            repeatres+=res;
            num--;
        }
        return repeatres;
    }
};
```

### 递归
```
class Solution {
public:
    string decodeString(string s) {
        int num = 0;
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                res.push_back(s[i]);
            } else if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                int cnt = 0;
                i++;
                string innerS;
                while (s[i] != ']' || cnt != 0) {
                    if (s[i] == '[') cnt++;
                    else if (s[i] == ']') cnt--;
                    innerS.push_back(s[i]);
                    i++;
                }
                string innerRes = decodeString(innerS);
                while (num > 0) {
                    res += innerRes;
                    num--;
                }
            }
        }
        return res;
    }
};
```
