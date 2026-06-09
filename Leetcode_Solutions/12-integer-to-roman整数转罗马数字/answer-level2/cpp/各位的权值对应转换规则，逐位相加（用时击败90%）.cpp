### 解题思路: 将输入整数num的每位数字,按照其数位的权重weight(1,10,10,1000)对应的不同转换规则,分别转换成罗马数字字符串,相加后得到最后的字符串。
    例如整数456:
        1.个位(6)转换为"VI",    s="VI";
        2.十位(50)转换为"L",    s="L"+"VI"="LVI";
        3.百位(400)转换为"CD",  s="CD"+"LVI"="CDLVI";

### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
        string s;
        int weight=0;
        while(num){
            s=RomanDigit(num%10,weight)+s;
            num/=10;
            ++weight;
        }
        return s;
    }
    string RomanDigit(int num,int weight){
        string s;
        char chars1[]={'I','X','C','M'},chars2[]={'V','L','D'};
        if(num<=3)
            while(num--)
                s+=chars1[weight];
        else if(num==4)
            s=s+chars1[weight]+chars2[weight];
        else if(num==5)
            s=chars2[weight];
        else if(num<=8){
            s=chars2[weight];
            num-=5;
            while(num--)
                s+=chars1[weight];
        }
        else if(num==9)
            s=s+chars1[weight]+chars1[weight+1];
        else
            ;
        return s;
    }
};
```