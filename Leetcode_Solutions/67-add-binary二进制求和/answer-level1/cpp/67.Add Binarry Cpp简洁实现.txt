### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int len=max(a.length(),b.length()),carry=0;
        a.insert(a.begin(),len-a.length(),'0');
        b.insert(b.begin(),len-b.length(),'0');
        string ans;
        for(int i=len-1;i>=0;i--){
            int temp=carry+a[i]-'0'+b[i]-'0';
            ans=to_string(temp%2)+ans;
            carry=temp/2;
        }
        if(carry)ans.insert(ans.begin(),'1');
        return ans;
    }
};
```