### 解题思路
两个数对应位相乘，再相加，用的比较笨的方法，看代码很容易懂。

### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        vector<int> an(num1.size()+num2.size(),0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num1.size();i++){
            for(int j=0;j<num2.size();j++){
                an[i+j]+=(num1[i]-'0')*(num2[j]-'0');
                if(an[i+j]>9){
                    an[i+j+1]+=an[i+j]/10;
                    an[i+j]=an[i+j]%10;
                }
            }
        }
        for(int i=an.size()-1;i>0;i--){
            if(an[i]!=0)
            break;
            an.pop_back();
        }
        for(int i=an.size()-1;i>=0;i--){
            ans.push_back(an[i]+'0');
        }
        return ans;
    }
};
```