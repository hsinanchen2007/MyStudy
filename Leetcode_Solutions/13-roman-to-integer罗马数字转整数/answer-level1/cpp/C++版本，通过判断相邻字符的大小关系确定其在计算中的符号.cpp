实际上只需要判断后一个字符是否比前一个字符对应的int值更大，并且是否满足题目中所举例的六种情况（后一个字符对应的int值是前一个字符对应的int值的5倍或者10倍），就可以确定出当前字符对应的数字在最终结果计算中对应的操作符号是加法还是减法。
举例说明string数据"IV"：
字符'I'对应的int值为1，字符'V'对应的int值为5，满足后一个字符对应的int值为前一个字符对应的int值的5倍或者10倍的关系，则字符'I'在最终结果计算中的操作符号是负号，即对应减法。

在代码实现中，利用两个数组分别按对应关系存放字符和数值，通过索引值建立二者的联系，并且对仅有一个字符的string进行特殊考虑。代码如下：
```
class Solution {
public:
    char charList[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int intList[7] = {1,5,10,50,100,500,1000};
    int romanToInt(string s) {
        int index=0;
        int res = 0;
        if(s[1]=='\0'){ return intList[Locate(s[0], charList)];}
        while(s[index+1]!='\0'){
            if(intList[Locate(s[index], charList)]*5==intList[Locate(s[index+1], charList)]
            || intList[Locate(s[index], charList)]*10==intList[Locate(s[index+1], charList)]){
                res = res - intList[Locate(s[index], charList)]; 
            }else res = res + intList[Locate(s[index], charList)];
            index++;
        }
        res = res + intList[Locate(s[index], charList)];
        return res;
    }
    int Locate(char x, char* c);

};

int Solution::Locate(char x, char* c){
    int index=0;
    while(1){
        if(c[index]==x) return index;
        else if(c[index]!='\0'){
            index++;
        }else return -1;
    }
}
```

