### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    //不会的原因在于：1:不知道怎么1+0余1，1+1余0（可以通过取模）
public:
    string addBinary(string a, string b) {
        //就像leetcode第二题两数相加一样，我们可以通过使用一个int型的count保存除下来得到的余数
        string ans;
        int count=0;
        for(int i=a.length()-1,j=b.length()-1;i>=0||j>=0;i--,j--){
            count+=i>=0?a[i]-'0':0;
            count+=j>=0?b[j]-'0':0;
            ans+=count%2+'0';
            count=count/2;  
        }
        if(count==1)
            ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```