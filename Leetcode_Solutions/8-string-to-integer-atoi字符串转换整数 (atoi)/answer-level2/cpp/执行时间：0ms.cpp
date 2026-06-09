### 解题思路
先对字符串进行修剪，然后利用c++中stringstream流进行转化

##### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int n;
        n = str.find_first_not_of(" ");
        if(n==string::npos)
            return 0;
        if(str[n]=='-'||str[n]=='+'||str[n]>='0'&&str[n]<='9'){
            int i = str.find_first_not_of("0123456789",n+1);
            if(i!=string::npos){
                str.erase(i,str.size());
            }
        }else{
            return 0;
        }
        stringstream s;
        s<<str;
        int re;
        s>>re;
        return re;
    }
};
```