![tu.jpg](https://pic.leetcode-cn.com/7a8abac70af6d1cebdd14c9293bfa836c0857cd22504978a3afa255d5724c3ba-tu.jpg)
```
class Solution {
public:
    char Xor(const char &a,const char &b){ //按位异或运算
    return ((a-48)^(b-48))+48;
}
char Alu(const char &a,const char &b,char &c){//运算单元的实现
        char s=Xor(Xor(a,b),c-48)+48; //输入Ai Bi Ci 输出Si即本位运算结果
         c=((((a-48)&(b-48)))|(Xor(a,b)&(c-48)))+48;  //符号位结果
        return s;
}
string addBinary(string a,string b){
    a="0"+a;//字符串首位补零
    b="0"+b;
    char c='0';//设置符号位默认为0
    string res="";
    int length=a.length()>=b.length()?a.length():b.length();
    for(int i=0;i<length;i++){
        if(i<a.length()&&i<b.length()){
        res=Alu(a[a.length()-1-i],b[b.length()-1-i],c)+res;
        }
        if(i<a.length()&&i>=b.length()){
            res=Alu(a[a.length()-1-i],'0',c)+res;
        }
        if(i<b.length()&&i>=a.length()){
            res=Alu(b[b.length()-1-i],'0',c)+res;
        }
    }
     if(res[0]=='0')//首位去0
    {
        string x(res.begin()+1,res.end());
        return x;
    }
   return res;
}

};
```

