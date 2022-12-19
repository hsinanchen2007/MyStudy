### 解题思路


### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
        vector<int> ans;
        ans.push_back(0);
        int z=0;
        for(int i=num2.size()-1;i>=0;i--)
        {
            int a=num2[i]-'0';
            int c=0,tag=z;
            for(int j=num1.size()-1;j>=0;j--)
            {
                int b=num1[j]-'0';
               
                if(tag>ans.size()-1){
                    ans.push_back(0);
                }
               int tmp=ans[tag];
                ans[tag]=(b*a+c+ans[tag])%10;
                tag++;
                c=(b*a+c+tmp)/10;
            }
            if(c!=0)ans.push_back(c);
            z++;
        }
        string str="";
        for(int i=ans.size()-1;i>=0;i--)
            str+=(ans[i]+'0');
        return str;
    }
};
```