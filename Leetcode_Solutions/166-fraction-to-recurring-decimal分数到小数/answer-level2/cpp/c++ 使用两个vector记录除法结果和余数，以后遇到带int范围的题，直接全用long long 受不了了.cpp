### 解题思路
有理数除以有理数一定得到的是有理数，无限循环小数是有理数，无限不循环小数是无理数，所以这道题如果得到无限小数，则一定是无限循环小数。
自己做几次除法就会发现规律，结果循环的部分，就是每次余数一样的时候，一个vector记录结果，一个vector记录余数（要按顺序保存，方便找到循环开始位置）。注意这两个vector的不同，记录结果的vector每次只记录小数点后的一位，这里面的数在0-9之间；记录余数的vector，这里面的数随便，可以很大。

因为最开始没有注意int的范围，所以写的时候都用的int，但是每次修改int范围后的提交都不接受，最后我生气了，把程序里面所有的变量都换成long long，把形参也换成了long long。最后通过，我是在没有办法了，这样的题太恶心了，每次都因为范围的问题无法通过。以后再遇到这种题（int型的加减乘除）直接都用longlong。

一会看看别人的答案，我自己想的方法肯定没被人的好


代码我注释了，可以参考一下，写的有点啰嗦了，可以优化的，但是不想再看这种题了。
![image.png](https://pic.leetcode-cn.com/98b9edbc8e7859ab6876acc9db36eb22878eeefaa0dd3dec632531a209fc2836-image.png)

![image.png](https://pic.leetcode-cn.com/391bc542a2a3644ebab2af7f8c5295686ae8c14c2c448f4445d14b26f0e373cc-image.png)



### 代码

```cpp
class Solution {//有理数除以有理数一定得到的是有理数，无限循环小数是有理数，无限不循环小数是无理数，所以这道题如果得到无限小数，则一定是无限循环小数。
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==0)
            return "";
        string res;//结果
        string flag="";//结果正负标志位，返回的时候直接加上
        if((numerator<0&&denominator>0)||(numerator>0&&denominator<0))
            flag="-";
        long long _numerator=numerator;//因为分子分母要求绝对值，INT_MIN求绝对值会超过范围，直接把他们变成long long
        long long _denominator=denominator;
        long long numerator_=abs(_numerator);//这个两个新的变量就是形参的long long形式
        long long denominator_=abs(_denominator);
        if(numerator_%denominator_==0)//直接可以整除，直接返回就可以了，不用讨论小数点后面的情况
        {
            res+=to_string(numerator_/denominator_);
            return flag+res;
        }
        else//无法整除，需要讨论小数点后面的情况（循环或者不循环）；循环的标志是每次计算得到的余数和之前的余数相同，这样就又开始重新执行
            //之前的计算了。不循环的标志是某次计算的余数为0
        {
            long long int_part=numerator_/denominator_;//计算整数部分
            res+=to_string(int_part);
            res+=".";//加上小数点
            long long mod_num=numerator_%denominator_;//获得余数，用于下一次计算
            vector<long long> point_list;//记录小数点后面的每一位的值
            vector<long long> mod_list;//记录余数的值，
            while(find(mod_list.begin(),mod_list.end(),mod_num)==mod_list.end())//在mod_list中找上次计算的余数是否存在，存在则说明循环
            {
                long long tmp=mod_num*10;//每次计算的余数是上次计算剩的，因此需要乘10,表示本次计算，自己列一个除法的那个计算过程就能看出来
                point_list.push_back(tmp/denominator_);//存入本次计算得到的小数点后面的位置
                mod_list.push_back(mod_num);//把余数放进去
                mod_num=tmp%denominator_;//重新计数余数
                if(mod_num==0)//余数==0，说明没循环直接跳出
                    break;
            }
            if(mod_num==0)//没循环，直接把point_list中的所有数加到结尾中
            {
                auto it=point_list.begin();
                while(it!=point_list.end())
                {
                    res.push_back('0'+*it);
                    ++it;
                }
                return flag+res;
            }
            //处理循环，首先根据余数的值找到循环开始位置，因为循环不一定是从小数点后一位开始的
            auto it=point_list.begin();
            auto it2=mod_list.begin();
            while(*it2!=mod_num)//用来找到循环开始的位置
            {
                ++it2;
                res.push_back('0'+*it);
                ++it;
            }
            res+="(";
            while(it!=point_list.end())//point_list剩余的部分就是循环部分
            {
                res.push_back('0'+*it);
                ++it;
            }
            res+=")";
            return flag+res;//返回结果
        }
    }
};
```