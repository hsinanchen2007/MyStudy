### 解题思路
回溯

### 代码

```cpp
class Solution {
public:
    int f=0;
    string add(string& a,string& b){//从其他大佬处复制的
        int n1=a.size()-1;
        int n2=b.size()-1;
        int carry=0;
        string ans;
        while(n1>=0||n2>=0||carry>0){
            int t1=n1>=0?a[n1--]-'0':0;
            int t2=n2>=0?b[n2--]-'0':0;
            ans+=(t1+t2+carry)%10+'0';
            carry=(t1+t2+carry)>=10?1:0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(string &num,int pos,string pre,string tmp,int cnt){//cnt是此时递归的是第几个数字
        if(pos==num.size()){
            if(cnt>=3) f=1;
            return;
        } 
        int i;
        string s;
        for(i=pos;i<num.size();i++){
            s=num.substr(pos,i-pos+1);
            if(s[0]=='0'&&i-pos>0) return ;//防止出现01,03这种数字
            if(cnt==0||cnt==1){//前两个数单独处理
                dfs(num,i+1,tmp,s,cnt+1);if(f) return ;
            }
            if(add(pre,tmp)!=s) continue;
            dfs(num,i+1,tmp,s,cnt+1);if(f) return ;
        }
    }
    bool isAdditiveNumber(string num) {
        if(num.size()<3) return false;
        dfs(num,0,"0","0",0);
        if(f) return true;
        return false;
    }
};
```