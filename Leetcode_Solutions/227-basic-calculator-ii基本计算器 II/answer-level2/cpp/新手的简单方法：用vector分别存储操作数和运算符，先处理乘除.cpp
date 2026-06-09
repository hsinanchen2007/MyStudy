### 解题思路
初学编程，记录一下自己的解题。
num依次存储数，op依次存储运算符，op的长度的num的长度减1。
![image.png](https://pic.leetcode-cn.com/4507d8ab682cd81ad4228a605f62d36cd3b7fdb37a89721f5692c93a3e39485f-image.png)
算法：忽略加号和减号，碰到符号i是乘（除号一样的操作），
则： 
     int 新数=数i*数i+1;
     从vector op中删除此操作符op[i]，
     从vector num中删除num[i+1];
     num[i]=新数；

要注意的是忽略加号减号的时候i++，操作一次之后i不需要变动。循环应该进行n次，n是最初的op的长度，我采用了while(n--)。
循环之后，op中只剩下加和减，最后依次取出操作数和操作符进行加减。
后缀表达式和栈还不太会，这两天抓紧学习一下。
### 代码

```cpp
class Solution {
public:
    int calculate(string s) {
    vector<int>num;
    vector<char>op;
    int l=s.size();
    string k;
    for(int i=0;i<l;i++)
    {
        if (s[i]==' ') continue;
        if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            int nu=stoi(k);
            k.clear();
            num.push_back(nu);
            op.push_back(s[i]);
        }
        else
        k+=s[i];
    }
     num.push_back(stoi(k));  //把最后一个数字存入，到这完成了把原始string转换为两个vector的操作
    int lop=op.size(),i=0;
      while(lop--)          //循环次数为op最初长度
    {   
        if(op[i]=='+'||op[i]=='-')
        {i++;continue;}
        if(op[i]=='*')
        {
            int re=num[i]*num[i+1];
            op.erase(op.begin()+i);
            num[i]=re;
            num.erase(num.begin()+i+1);
        }
        else 
        {
            int re=num[i]/num[i+1];
            op.erase(op.begin()+i);
            num[i]=re;
            num.erase(num.begin()+i+1);
        }
    }                                //循环完毕，此时op中只有加和减
    int sum=num[0],j=op.size();
    for(int i=0;i<j;i++)
    {
        if(op[i]=='+')
        sum+=num[i+1];
        else
        sum-=num[i+1];
    }
    return sum;
    }
};
```