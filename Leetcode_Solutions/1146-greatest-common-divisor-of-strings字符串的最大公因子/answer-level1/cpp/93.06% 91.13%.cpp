

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1) return ""; //先判断是不是相同的字符串组成
        int n=str1.length(),m=str2.length(); //求出各字符串的长度
        int gcd=__gcd(n,m); //通过C++（algorithm库中？）自带的求最大公约数
        int i=0;
        string ans=""; //定义存储结果的存储器
        for(;i<gcd;++i){
            if(str1[i]!=str2[i]) break; //如果有不相等的情况直接跳出循环
            ans+=str1[i];
        }
        if(i!=gcd) return "";
        else return ans;
    }
};
//另__gcd，个人喜欢写成这样，还望各位大佬指点，谢谢！
int __gcd(int i,int j){
        int i;
        while(j>0){
            t=i%j;
            i=j;
            j=t;
        }
        return i;
}