### 产生式
整数 = 无符号整数 | 有符号整数
有符号整数 = 符号&无符号整数
无符号整数 = 无符号整数

小数 = 无符号小数 | 有符号小数
有符号小数 = 符号&无符号小数字
无符号小数 = 无符号整数&小数点 | 小数点&无符号整数 | 无符号整数&小数点&无符号整数

指数 = 整数&指数符号&整数 | 小数&指数符号&整数
```
"0"
"+5"
"-3"
"2."
".3"
"1.5"
"0e+5"
"+5e-3"
"-3e-7"
"56.1e8"
"3.e+6"
"+7.5e-32"
".7e+8"
```

### 血泪

![手测文法.png](https://pic.leetcode-cn.com/43123ee787cfb4b771f667370c43b13fee534b1b197aa0ea550c7587b2753f74-%E6%89%8B%E6%B5%8B%E6%96%87%E6%B3%95.png)

### 代码

自动机并不大，就转为数值串查表了，自己建自动机一个也是极好的。

```cpp
class Solution {
public:
    bool isNumber(string s){
        while(s.size()&&s[0]==' '){
            s=s.substr(1);
        }
        while(s.size()&&s[s.size()-1]==' '){
            s=s.substr(0,s.size()-1);
        }
        vector<int> vc;
        int t=0; //token 1:正负号 2:连续数字 3:小数点 4:E或e
        for(auto e:s){
            if(e=='+'||e=='-') t=1;
            else if(e>='0'&&e<='9') t=2;
            else if(e=='.'){
                 t=3;
            }
            else if(e=='E'||e=='e') t=4; //测试用例只支持e,E仅仅会在自己测试输出false，估计测试用例里没用E.
            else t=5;
            //粗过滤，遇到不可能直接退出
            if(t==2&&vc.size()&&vc.back()==2){
                continue;
            }
            if(t==3&&vc.size()&&(vc.back()==4||vc.back()==3)){
                return false;
            }
            if(t==4&&vc.size()&&vc.back()==1){
                return false;
            }
            vc.push_back(t);
        }
        long ans=0;
        for(auto e:vc){
            ans*=10;
            ans+=e;
        }
        set<int> saw={
            2,12, //整数
            23,32,232,  123,132,1232, //小数
            242,1242,2342,3242,23242,12342,13242,123242, //指数
            2412,12412,23412,32412,232412,123412,132412,1232412, //指数
                      };
        return saw.count(ans)==1;
    }
};
```