### 解题思路
执行用时击败85.86%，效率还可以。
题目不难，但是需要判断的东西比较多；
需要完成的操作：
1、消去前缀的空格和0；
2、消去后缀的无效字符；
做完1和2后：
3、判断新前缀是否是无效字符，是的就返回0；
4、判断新字符串的长度是否大于10，大于就肯定超过了int的表示范围；
5、在过程中（结果也可以）判断是否超过了int的表示范围，超过了就根据正负值输出相应的值。

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        long long ans;
        //处理无用空格开头
        while(str[0]==' ') str.erase(0,1);
        //判断第一个字符是否是整数或者正负号
        if (str[0]=='+') ans=Trans(str.substr(1,str.size()-1),true);
        else if (str[0]=='-') ans=Trans(str.substr(1,str.size()-1), false);
        else if ( str[0]-'0'>=0 && str[0]-'0' <=9) ans=Trans(str.substr(0,str.size()), true);
        else ans=0;//前缀为无效字符

        return ans;
           
    }
    int Trans(string s, bool isPos ){
        int k=0;
        //处理前面出现的若干个0
        while(s[0]-'0'==0){
            s.erase(0,1);
        }
        //处理整数后面的无用字符
        while(s[k]-'0'>=0 && s[k]-'0'<=9) k++;
        s.erase(k, s.size()-k);
        long long temp=0;
        int len=0;
        k=s.size()-1;
        if(s.size()>10){//位数大于10的必然超过了int的表示范围
            if (!isPos) return INT_MIN;
            else return INT_MAX;
        }
        while(len < s.size()){
            temp+=(s[k]-'0')*pow(10,len);
            //注意计算过程中可能超过long long的表示范围，一旦超过int的范围立刻返回
            if (!isPos && temp>INT_MAX) return INT_MIN;
            if (isPos && temp>=INT_MAX) return INT_MAX;
            len++;
            k--;
        }
        if(isPos) return (int)temp;
        else return (int)0-temp;
    }
};
```