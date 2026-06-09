```
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()) return b;
        if(b.empty()) return a;
        
        string s="";        //储存结果
        int res=0;          //每位结果
        int tem=0;         //进位
        int lena=a.size();
        int lenb=b.size();
        while(lena>lenb) { 
            b='0'+b;
            lenb++;
        }
        while(lenb>lena) { 
            a='0'+a;
            lena++;
        }
        for(int i=lena-1;i>=0;i--) {
           res=tem+a[i]+b[i]-'0'-'0';
           tem=res/2;
           res=res%2; 
           s.insert(s.begin(),res+'0');
            }
        if(tem==1)     s.insert(s.begin(),'1');
        return s;
    }
};
```
