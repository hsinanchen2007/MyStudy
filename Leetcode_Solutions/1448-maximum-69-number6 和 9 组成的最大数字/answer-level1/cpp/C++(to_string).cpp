```
class Solution {
public:
    int maximum69Number (int num) {
        //个人觉得遇到6变成9，完事，如果全部为9，则不变。
        //char ans[10];
        //vector<char>ans;
        string ans;
        ans=to_string(num);
        int n=ans.size();
        bool flag=false;
        for(int i=0;i<n;i++){
            if(ans[i]=='6'){
                ans[i]='9';
                flag=true;
                break;
            }
        }
        if(!flag)return num;
        int res=0;
        for(int i=0;i<n;i++){
            res=res*10+(ans[i]-'0');
        }
        return res;
    }
};
```
