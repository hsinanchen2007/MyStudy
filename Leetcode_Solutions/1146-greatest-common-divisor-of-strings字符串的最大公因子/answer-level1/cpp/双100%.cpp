### 解题思路
减少了io操作

### 代码

```cpp
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    /*先判断A+B 是否等于 B+A， 不相等，则没有公因子。
    相等的话，就找两者长度的最大公因子。并返回字符串从0到公因子的长度即可。
    */
    int myGcd(int a,int b){
        while(a!=0&&b!=0){
            a%=b;
            if(a==0){
                break;
            }
            swap(a,b);
        }
        return b;
    }

    string gcdOfStrings(string str1, string str2) {
        if((str1+str2)!=(str2+str1)){
            return "";
        }

        int com=myGcd(str1.size(),str2.size());
        return str1.substr(0,com);
    }
};
```