### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string ans;
        int i=a.size()-1,j=b.size()-1;
        while(i>=0||j>=0||carry!=0){
            int sum=0;
            if(i>=0)sum+=a[i--]-'0';
            if(j>=0)sum+=b[j--]-'0';
            sum+=carry;
            ans+=sum%2+'0';
            carry=sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```