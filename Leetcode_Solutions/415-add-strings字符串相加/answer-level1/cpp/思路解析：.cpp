### 解题思路
1.利用for循环，从字符串末尾至首依次相加
    注意：1.字符串每个元素减0化为整数再相加，
        ：2.相加时记得加上weight（进位数）
        ：3.最高位如果有进位数，需要push单字符串
2.将结果逆置：
    从尾部开始相加，push到res，因此要逆转过来


### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        // 进位数
        int weight = 0;
        int a,b,temp;
        string res;
        for(int i = num1.length()-1, j = num2.length()-1;i >= 0||j >= 0;i--,j--) {
            // 将字符转化为整数
            a=b=temp =0;
            if (i>=0) a=num1[i]-'0';
            if (j>=0) b=num2[j]-'0';
            temp =a+b+weight;
            res.push_back((temp%10)+'0');
            weight = temp /10;
        }
        // 输出最高位
        if(weight != 0) {
            res.push_back(weight +'0');
        }
        // 结果倒转
        char t;
        for(int i=0;i<res.length()/2;i++) {
            t = res[i];
            res[i] = res[res.length()-1-i];
             res[res.length()-1-i] = t;
        }
        return res;
    }
};
```