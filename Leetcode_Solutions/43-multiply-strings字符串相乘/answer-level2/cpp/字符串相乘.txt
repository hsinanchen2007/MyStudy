利用错位相乘的法则求解，注意第i位和第j位相乘之后出现的位置为i+j和i+j+1两个位置，为此我们定义了一个vector<int> dp(m+n,0)，对于num1和num2不同位置两两相乘，低位的时候注意加上原始的结果，然后取余即可得到低位结果，高位结果需要加和，错位相乘即可。

```
class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size(),n=num2.size();
        vector<int> vals(m+n);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int p1=i+j,p2=i+j+1,sum=mul+vals[p2];
                vals[p1]+=sum/10;
                vals[p2]=sum%10;
            }
        }
        string res="";
        for(auto val:vals){
            if(!res.empty() || val!=0) res.push_back(val+'0');
        }
        
        return res.empty()?"0":res;
    }
};
```