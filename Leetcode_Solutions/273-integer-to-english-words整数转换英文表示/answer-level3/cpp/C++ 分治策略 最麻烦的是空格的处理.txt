其实本题并不是很难，关键在于分类情况的逻辑要清晰，还有空格的处理要符合规范。参考代码如下：
```
class Solution {
public:
    string small[20] = {"","One","Two","Three","Four","Five","Six","Seven",
                           "Eight","Nine","Ten","Eleven","Twelve","Thirteen",
                           "Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string decade[10] = {" "," ","Twenty","Thirty","Forty","Fifty","Sixty",
                        "Seventy","Eighty","Ninety"};
    string big[4] = {"Billion","Million","Thousand"," "};
    string ret;
    
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        for(int i = 1000000000,j = 0;j<4; i /= 1000,j++){
            int tp = num/i;
            if(tp != 0){
                ret += helper(tp) + " " + big[j] + " ";
                num %= i;
            }
        }
        while(ret.back() == ' '){
            ret.pop_back();
        }
        return ret;
    }
    
    string helper(int num){
        string ret;
        if(num /100 != 0){
            ret += small[num / 100] + " Hundred ";
            num %= 100;
        }
        if(num >= 20){
            ret += decade[num/10] + " ";
            num %= 10;
        }
        if(num < 20){
            ret += small[num] + " ";
        }
        while(ret.back() == ' '){
            ret.pop_back();
        }
        return ret;
    }
};
```
