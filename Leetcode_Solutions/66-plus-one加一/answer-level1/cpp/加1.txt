```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--)
        {
            //cout<<digits[i]<<endl;
            if(digits[i]==9)
            {
                digits[i]=0;
            }
            else
            {
                digits[i]++;
                break;
            }
        }
        if(digits[0]==0)
        {
            digits.push_back(0);
            digits[0]=1;
        }
        return digits;
    }
};
```
2020.1.8 饱读诗书小码农的日常 
这是今天自己的第二道题：
本来的思路是转化为str  str 转化为int  然后加1 这样就不会有进制的烦恼了
但是进行了写代码后发现，转化为int 会有 很大的问题所在，就是溢出的问题，当给的str的长度超过int 的时候，用unsigned long long 都是没有办法解决的，所以自己在尝试以一番之后，放弃了这种思想
但是对于上面的思想，还是有学习到一些知识的，进行总结：
1. c_str() 是string 类型转化为char[] 字符串类型的
2. to_string  是int 转化为string 类型的
3. atoi 是char [] 类型向 int 类型的转化
4. string 向int 的转化用的是 stoi() 这个函数 当然也可以像string 用c_str 转化为 char [] ,然后 char [] 在转化为 int 

然后积极去看了题解，哇真的思路清奇但是又恰到好处，自己真的是佩服，不经感慨 难怪这么多人在leedcode 上练习编程的能力


第二种解法是题解里面的，自己看懂后自己实现了一遍：
总结一下：
首先就是遇到9 和非9 的处理
遇到9 那么直接设置为0，然后在到前一位在查看是否是9 如果是还是设置为0，直到循环到没有9 为止。
对于第一个非9的数字直接加1 然后跳出整个循环。

最特殊的处理就是数字全是9 的处理，例如999
那么这个就要在push_bach 一位进来，然后vector的第一位改成 1 


这种思想真的很OK。

自己 废话一大推，写题解只是为了让自己思路更加清晰哈
