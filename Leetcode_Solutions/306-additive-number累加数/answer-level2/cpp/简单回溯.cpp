### 解题思路
简单回溯

### 代码

```cpp
class Solution {
public:
    int n;
    bool flag=false;
    bool isAdditiveNumber(string num) {
        n = num.size();
        vector<string>t;
        dfs(num,0,t);
        return flag;
    }
    void dfs(string& num,int start,vector<string>&t){
        if(flag)return;
        int q=t.size();
        if(q>2){
            if(t[q-1]!=addStrings(t[q-2],t[q-3]))return ;
            if(start==n){
                flag=1;
                return ;
            }
        }
        for(int i=start;i<n;i++){
            string temp = num.substr(start,i-start+1);
            if(num[start]=='0'){
                temp="0";
            }
            t.push_back(temp);
            dfs(num,i+1,t);
            t.pop_back();
        }
    }
    string addStrings(string& num1, string& num2) {
        string res;
        int carry = 0;
        for(int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; i--, j--)
        {
            int sum = carry;
            sum += (i >= 0) ? num1[i] - '0' : 0;
            sum += (j >= 0) ? num2[j] - '0' : 0;
            res.insert(res.begin(), '0' + sum % 10);
            carry = sum / 10;
        }
        if(carry == 1)
            res.insert(res.begin(), '1');
        return res;
    }
};
```