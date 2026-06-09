在小数部分如果出现两次除数相同的情况即说明是循环小数，话不多说，代码如下：
```
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        if(denominator == 0)
            return result;
        long long num = static_cast<long long>(numerator);
        long long denom = static_cast<long long>(denominator);
        //处理符号
        if((num < 0 && denom > 0) || (num > 0 && denom < 0))
            result += "-";
        num = abs(num);
        denom = abs(denom);
        //处理整数部分
        result += to_string(num / denom);
        num %= denom;
        //处理小数部分
        if(num)
            result += ".";
        //利用hash表记录出现过的除数从而定位循环
        unordered_map<long long, int> map;
        int index = 0;//当前index - map[num]可以定位循环的长度
        while(num && map.find(num) == map.end()) {
            map[num] = index++;
            num *= 10;
            result += to_string(num / denom);
            num %= denom;
        }
        //如果是出现了循环小数
        if(map.find(num) != map.end()) {
            result += "()";
            int cur = result.size() - 2;
            while(index-- > map[num]) {
                swap(result[cur], result[cur - 1]);
                --cur;
            }
        }
        return result;
    }
};
```