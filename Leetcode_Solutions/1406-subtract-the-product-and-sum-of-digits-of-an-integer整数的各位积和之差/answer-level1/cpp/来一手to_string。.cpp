### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        string s=to_string(n);
        int m=1,sum=0;
        for(int i=0;i<s.length();i++){
            m*=s[i]-'0';sum+=s[i]-'0';
        }
return m-sum;

    }
};
```