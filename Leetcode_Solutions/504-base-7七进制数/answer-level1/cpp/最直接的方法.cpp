### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)return "0";
        string ans;
        int temp=abs(num);
        while(temp){
            int a=0;
            a=temp%7;
            ans+=to_string(a);
            temp/=7;
        }
        if(num<0)ans+='-';//如果为负数要加一个-
        reverse(ans.begin(),ans.end());//反转字符串
        return ans;
    }
};
```