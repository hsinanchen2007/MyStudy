因为是只有四段，也就是递归深度也是确定的。这里直接采用四重循环的形式，用continue进行剪枝。
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.empty()) return {};
        vector<string> res;
        int len=s.size();
        for(int i=1;i<4;i++)
            for(int j=1;j<4;j++)
                for(int k=1;k<4;k++)
                    for(int l=1;l<4;l++)
                    {
                        // 长度不满足
                        if(i+j+k+l!=len) continue;
                        // 非零数字第一位为0（注意是字符'0'）
                        if(i>1 && s[0]=='0') continue;
                        if(j>1 && s[i]=='0') continue;
                        if(k>1 && s[i+j]=='0') continue;
                        if(l>1 && s[i+j+k]=='0') continue;
                        // 数字大于255
                        string s1=s.substr(0,i);
                        if(stoi(s1)>255) continue;
                        string s2=s.substr(i,j);
                        if(stoi(s2)>255) continue;
                        string s3=s.substr(i+j,k);
                        if(stoi(s3)>255) continue;
                        string s4=s.substr(i+j+k,l);
                        if(stoi(s4)>255) continue;
                        res.push_back(s1+'.'+s2+'.'+s3+'.'+s4);
                    }
        return res;
    }
};