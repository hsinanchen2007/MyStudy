### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry=0;
        string ans="";
        int idx1=num1.size()-1,idx2=num2.size()-1;
        while(idx1>=0||idx2>=0||carry!=0){
            int sum=0;
            if(idx1<0&&idx2<0)sum=carry;
            else if(idx1<0&&idx2>=0)sum=(num2[idx2--]-'0')+carry;
            else if(idx1>=0&&idx2<0)sum=(num1[idx1--]-'0')+carry;
            else sum=(num1[idx1--]-'0')+(num2[idx2--]-'0')+carry;
            ans+=to_string(sum%10);
            carry=sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```