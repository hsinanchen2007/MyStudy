```
class Solution {
public:
    string addStrings(string num1, string num2) {
        //补齐两个字符串
        while(num1.size()>num2.size())
            num2='0'+num2;
        while(num2.size()>num1.size())
            num1='0'+num1;
            char add;
            //进位carry
            int carry=0;
        for(int i=num1.size()-1;i>=0;i--)
        {
            //相同位字符串相加再加进位的结果
            add=num1[i]+num2[i]-'0'+carry;
            if(add>'9')
            {
                //结果存储在num2中
                num2[i]=add-10;
                carry=1;
            }
            else
            {
                num2[i]=add;
                carry=0;
            }
        }
        //0索引有进位则在前面放1
        if(carry==1) return ("1"+num2);
        else return num2;
    }
};
```
