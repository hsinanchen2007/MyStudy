### 解题思路


### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        string ans(n1+n2,'0');//两数相乘，位数不大于两数长度之和
        for(int i=n2-1;i>=0;i--){
            for(int j=n1-1;j>=0;j--){//从后到前计算，当前位置=当前数+当前两数之级
                int temp=(num1[j]-'0')*(num2[i]-'0')+(ans[i+j+1]-'0');
                ans[i+j+1]=temp%10+'0';
                ans[i+j]+=temp/10;//前一个数进位更新
            }
        }
        for(int i=0;i<n1+n2;i++){
            if(ans[i]!='0') return ans.substr(i);
        }
        return "0";
    }
};
```