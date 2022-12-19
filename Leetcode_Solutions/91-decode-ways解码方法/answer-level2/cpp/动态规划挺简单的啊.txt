### 解题思路
我觉得考虑0是很正常的啊，五分钟就搞定了
### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int i,j,n=s.size();
        vector<int>a(n+1,0);a[0]=1;
        if(s[0]=='0')return 0;//首字符为0直接返回0
        a[1]=1;
        for(i=1;i<n;i++){
            j=(s[i-1]-'0')*10+s[i]-'0';//和前一个字符合起来的值
            if(s[i]>'0')a[i+1]=a[i];//此处不为0，继承前一项的方法数
            if(j>9&&j<=26)a[i+1]+=a[i-1];//如果和前面一项合起来在10~26直接，则再加上前两项的数
            if(a[i+1]==0)return 0;//出现不合法直接返回0
        }
        return a[n];
    }
};
```