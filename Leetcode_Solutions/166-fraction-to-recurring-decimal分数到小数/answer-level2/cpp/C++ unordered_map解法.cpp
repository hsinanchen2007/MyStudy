详细讲解可参考我的博客：

https://blog.csdn.net/gjh13/article/details/99565153

代码如下：

```
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //如果除数是0，就直接返回0
        if(numerator == 0) return "0";
        //用flag来判断正负
        int flag = 1;
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) flag = -1;
        string res;
        if(flag == -1) res += '-';
        
        //需要注意int型的整数范围，最小的负数去反之后，会超出int的表示范围，所以要改成long型
        long numer = numerator;
        long denomin = denominator;
        if(numer < 0) numer = -1 * numer;
        if(denomin < 0) denomin = -1 * denomin;
        
        //这一部分先处理结果的整数部分，分为两种情况：整数部分为0，整数部分大于0
        if(numer < denomin) res += "0.";
        else{
            res += to_string(numer / denomin);
            numer = numer % denomin;
            if(numer > 0) res += '.';
        }
        
        //下面处理小数部分
        //用unordered_map来记录出现的余数，当出现重复的余数时，就是出现了循环
        unordered_map<long, string> mp;  //存储<余数, 商>
        vector<string> num;  //num中记录每一次除法得到的商
        string xunhuanshang;
        while(numer > 0){
            unordered_map<long, string>::iterator it;
            it = mp.find(numer);
            string tmp;
            long shang;
            if(it == mp.end()){
                long count = 0;   //用于记录需补0的个数
                long numer_tmp = numer;
                while(numer_tmp < denomin){
                    numer_tmp *= 10;
                    count++;
                }
                while(count > 1){
                    tmp += '0';
                    count--;
                }
                shang = numer_tmp / denomin;
                long yushu = numer_tmp % denomin;
                
                mp[numer] = tmp + to_string(shang);
                string tmpp = tmp + to_string(shang);
                num.push_back(tmpp);
                numer = yushu;
            }
            else {
                xunhuanshang = mp[numer];
                break;
            }
        }
        
        for(int i = 0; i < num.size(); i++){
            if(num[i] == xunhuanshang){  //找到循环开始的商
                res += '(';
                for(int j = i; j < num.size(); j++)
                    res += num[j];
                res += ')';
                break;
            }
            else{
                res += num[i];
            }
        }
        return res;
    }
};
```

