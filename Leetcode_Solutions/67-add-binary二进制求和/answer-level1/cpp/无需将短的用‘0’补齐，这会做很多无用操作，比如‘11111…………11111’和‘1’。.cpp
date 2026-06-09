class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size(), len_b = b.size(), i, j;
        string ans, ops;
        if(len_a >= len_b) {
            ans = a;
            ops = b;
        }
        else{
            ans = b;
            ops = a;
        }
        char add = '0';
        for(i=(ans.size()-1); i>=(ans.size()-ops.size()); i--)
        {
            ans[i] = ans[i] - '0' + ops[i-(ans.size()-ops.size())] - '0' + add;
            if(ans[i]=='0' || ans[i]=='1') add = '0';
            else if(ans[i]=='2'){
                add = '1';
                ans[i] = '0';
            }
            else if(ans[i]=='3'){
                add = '1';
                ans[i] = '1';
            }
            if(i == (ans.size()-ops.size())) break;
        }
        if(i==0 && add=='0') return ans;
        else if(i==0 && add=='1') return '1'+ans;
        else if(i!=0 && add=='0') return ans;
        else if(i!=0 && add!='0'){
            for(j=(i-1); j>=0; j--){
                ans[j] = ans[j] - '0' + add;
                if(ans[j]=='1') return ans;
                else if(ans[j]=='2'){
                    add = '1';
                    ans[j] = '0';
                }
                else{
                    add = '1';
                    ans[j] = '1';
                }
                if(j==0) break;
            }
            if(j==0 && add=='0') return ans;
            else if(j==0 && add=='1') return '1'+ ans;
        }
        return 0;
    }
};