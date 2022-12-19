### 解题思路
1)value=value * 10+str[i]-'0',这条语句当在边界是会报错，因为越界，当value * 10+str[i]-'0'=INT_MAX时，我以为没越界，但是这条语句的计算过程中出现了越界，即value * 10+str[i]>INT_MAX,正确的形式为value * 10+(str[i]-'0').

2)2^31=1<<31是大于INT_MAX的，不能用int表示。同时2e31指的是2*10^31,不是2^31;其次pow(2,31)返回值为double.

3)负值计算时把负号带进去计算，不能说先计算出绝对值最后再加负号，因为int可以表示-2^31次方，但无法表示2^31,所以无法得到-2^31的绝对值。

4)其实也可以用long long来表示结果这样不会再计算中越界，把结果和INT_MAX比较看是否结果越界，但不是太好，因为如果把要求改为不超过long long 的范围将难以处理。

5)可以对字符串进行预处理把它的头部空格什么的处理一下。
### 代码

```cpp

class Solution {
public:
    int strToInt(string str) {
       int value=0,met_num=0,met_sign=0;
       double max=pow(2,31);
       for(int i=0;i<str.size();i++){
           if(met_num==1&&(str[i]>'9'||str[i]<'0'))break;
           else if(met_num==1&&str[i]>='0'&&str[i]<='9'){
               //判断计算后的数值是否越界
               if(met_sign==1) {//负数
                   if ((-1 * max + str[i] - '0') / 10 <= value)//越界
                       value = value * 10 - (str[i] - '0');
                   else return INT_MIN;
               }
               else{//正数
                   if((max-1-(str[i]-'0'))/10>=value)//越界
                   {
                        value=value*10+(str[i]-'0');
                   }
                   else return INT_MAX;
               }
           }
           else if(met_num==0&&met_sign==0){
               if(str[i]=='-'){
                   met_sign=1;//负号
               }
               else if(str[i]=='+')
                   met_sign=2;//正号
               else if(str[i]>='0'&&str[i]<='9'){
                   met_num=1;
                   value=str[i]-'0';
               }
               else if(str[i]!=' ')break;
           }
           else if(met_num==0&&met_sign!=0){
               if(str[i]<='9'&&str[i]>='0'){
                   met_num=1;
                   value=str[i]-'0';
                   if(met_sign==1)value*=(-1);
               }
               else return 0;
           }
       }
       if(met_num==0)return 0;
       return value;
    }
};
```