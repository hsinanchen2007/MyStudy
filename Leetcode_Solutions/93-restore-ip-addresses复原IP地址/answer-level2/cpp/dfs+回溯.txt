### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    string curr;
    vector<string> res;
    string s;
public:
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        if(s.length()<4 || s.length()>12) return res;

        dfs(0,4);
        return res;
    }

    void dfs(int start,int num){
        if(num==0 && start==s.length()){
            for(int k=0; k<curr.length();k++){
                if(curr[k]=='0' && ((k-1>-1 && curr[k-1]=='.') || (k-1==-1)) && k+1<curr.length() && curr[k+1]!='.') return;
            }
        }
        if(num==0 && start==s.length()){
            res.push_back(curr);
            res[res.size()-1].erase(res[res.size()-1].end()-1);
            return;
        }else if(num==0) return;
        else if(start == s.length()) return;
        int i=start;
        int flag=1;
        for(;i<start+3;i++){
            if(i<s.length() && (i==start || i==start+1 || (i==start+2 && ((s[start]-'0')*100 + (s[start+1]-'0')*10 + (s[i]-'0'))<=255))){
                curr+=s[i];
                curr+='.';
                dfs(i+1,num-1);
                curr.erase(curr.end()-1);
            }
            else {
                flag=0;
                break;
            }
        }
        if(flag) curr.erase(curr.end()-3,curr.end());
        else{
            if(i==start);
            if(i==start+1){
                curr.erase(curr.end()-1);
            }
            else{
                curr.erase(curr.end()-2,curr.end());
            }
        }
    }
};
```