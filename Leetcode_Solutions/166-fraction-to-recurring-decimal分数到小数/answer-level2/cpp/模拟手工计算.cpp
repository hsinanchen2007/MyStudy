首先判断结果正负，sign=(n*d<0), true表示有符号即负数；
然后对被除数、除数求绝对值n,d，可以不进行分数约分（即求最大公约数），模拟手工计算除法，并用哈希集合存储当前被除数n是否出现过；
如果曾经出现，则确定是循环小数；
最后将正负号+整数部分+小数点+小数部分返回。
其中可以使用哈希映射存储<被除数,小数部分下标>，确定循环部分的区间。
```
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool sign=(1L*numerator*denominator<0L);
        long n=labs((long)numerator), d=labs((long)denominator), i;
        string integer((sign?"-":"")+to_string(n/d)), fraction;
        unordered_map<long,long> dict;
        for(n=(n%d)*10, i=0; n && !dict.count(n); n=(n%d)*10){
            dict[n]=i++;
            fraction.push_back('0'+n/d);
        }
        if(!n) return integer+(fraction.length()?"."+fraction:"");
        return integer+"."+fraction.substr(0,dict[n])+"("+fraction.substr(dict[n])+")";
    }
};
```
