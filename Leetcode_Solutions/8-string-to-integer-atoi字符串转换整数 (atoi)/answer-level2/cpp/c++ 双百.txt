### 解题思路
![image.png](https://pic.leetcode-cn.com/7d3c076c528b632097cb8e46eb43f83b010e59b8999b0a29c97e6e74910110ed-image.png)

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int i=0,ans=0;
        while(i<str.size()&&str[i]==' ')i++;
        if(i==str.size()||!isdigit(str[i])&&str[i]!='-'&&str[i]!='+')return 0;
        else
        {
            bool f=0;
            if(str[i]=='-')
            {
                f=1;
                i++;
            }
            else if(str[i]=='+')i++;
            while(i!=str.size()&&isdigit(str[i]))
            {
                int d=str[i]-'0';
                if(ans>(INT_MAX-d)/10)return f==0?INT_MAX:INT_MIN;
                ans=ans*10+(str[i]-'0');
                i++;
            }
            if(f==1)ans=-ans;
        }
        return ans;
    }
};
```