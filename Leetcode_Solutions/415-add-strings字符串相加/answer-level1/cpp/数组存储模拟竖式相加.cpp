### 解题思路
数组存储模拟竖式相加

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> x,y,z;
        for(int i=num1.size()-1;i>=0;i--)
            x.push_back(num1[i]-'0');
        for(int i=num2.size()-1;i>=0;i--)
            y.push_back(num2[i]-'0');
        while(x.size()<y.size())
            x.push_back(0);
        while(y.size()<x.size())
            y.push_back(0);
        int op=0;
        for(int i=0;i<x.size();i++){
            op=x[i]+y[i]+op;
            z.push_back(op%10);
            op/=10;
        }
        if(op!=0)
            z.push_back(op);
        string res;
        for(int i=z.size()-1;i>=0;i--)
            res+=to_string(z[i]);
        return res;
    }
};
```