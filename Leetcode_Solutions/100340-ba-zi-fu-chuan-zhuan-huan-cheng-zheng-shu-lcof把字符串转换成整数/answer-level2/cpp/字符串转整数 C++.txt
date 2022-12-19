```
class Solution {
public:
    int strToInt(string str) {
        if(str.empty()) return 0;
        int i = 0;
        while(i<str.size() && str[i] == ' ') i++; //跳过空格
        if(i == str.size()) return 0; //无字符返回false

        long long res = 0; //处理越界
        int sign = 1; //标记正负
        if(str[i] == '-' ||str[i] == '+'){ //跳过符号位
            sign = !(str[i] == '-'); //+为1，-为0
            i++;
        }
        for(;i<str.size(); i++){
            if(str[i]>='0' && str[i]<='9'){ //只处理数字
                res = res*10+(str[i]-'0'); //逐项相加
                if(res-1>=INT_MAX){ //越界直接返回
                    return sign?INT_MAX:INT_MIN;
                }
            }
            else break; //其余均为非法字符break
        }
        return sign? res:-res;
    }
};
```
