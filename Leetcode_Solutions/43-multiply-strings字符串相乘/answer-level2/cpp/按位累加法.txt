### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void add(string& num2,string const n){
        int l1=num2.size(),l2=n.size();
        int a,b,up=0;
        for(int i=1;i<=l2;++i){
            a=(num2[l1-i]-'0')+(n[l2-i]-'0')+up;
            b=(a>9)?(a-10):a;
            num2[l1-i]='0'+b;
            up=a/10;
        }
        a=0;
        if(up==1){
            if(l1==l2){
            string s="1";
            num2=s+num2;}
            else{
                for(int j=l1-l2-1;j>=0;--j){
                    if(num2[j]<'9') {++num2[j];a=0;break;}
                    else {num2[j]='0';a=1;}
                }
            }
            if(a==1){string s="1";num2=s+num2;}
        }
        return;
    }
    string multiply(string num1, string num2) {
        if(num1[0]=='0'||num2[0]=='0') return "0";
        vector<string> nums;
        int pl;
        for(int k=0;k<num1.size();++k){
            if(num1[k]=='0'){nums.push_back("0");continue;}
            string tmp2=num2;
            for(int o=1;o<num1.size()-k;++o){
                tmp2+="0";
            }
            string tmp20=tmp2;         
            for(int q=1;q<(num1[k]-'0');++q){
                add(tmp2,tmp20);
            }
            nums.push_back(tmp2);
        }    
        for(int k=1;k<nums.size();++k){
            add(nums[0],nums[k]);
        }    
        return nums[0];
    }
};
```