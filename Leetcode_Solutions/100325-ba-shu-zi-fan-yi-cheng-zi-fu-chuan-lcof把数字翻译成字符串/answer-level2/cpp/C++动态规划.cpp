### 解题思路
注意表达10～25的写法。取了string就不可以再用str[]表示里面的数字，因为此时他是char。

### 代码

```cpp
class Solution {
public:
    int translateNum(int num) {
        string str=to_string(num);
        int a[11];//?????
        a[0]=1;
        if(str[0]=='0'||str.substr(0,2)>"25")
            a[1]=1;
        else a[1]=2;
        
        for(int i=2;i<str.size();i++)
        {
            if(str[i-1]=='0'||str.substr(i-1,2)>"25")
                a[i]=a[i-1];
            else a[i]=a[i-1]+a[i-2];

        }
        return a[str.size()-1];

    }
};
```