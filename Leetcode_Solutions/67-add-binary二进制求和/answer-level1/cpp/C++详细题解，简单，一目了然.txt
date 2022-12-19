
该题很容易想到直接模拟人工运算，该方法可行，但特别容易出错，而且也比较难找bug
所以我们可以换一个角度想想，只用一个标志变量tag
填充到目的字符串中，在while(tag == 1 || la >= 0 || lb >= 0)循环下
根据if(la >= 0 && a[la--] == '1')和if(lb >= 0 && b[lb--] == '1')
判断是否让tag自增，此时，tag%2就是要填充到目的字符串的数字了
通过c.insert(0,1,(char)(tag % 2 + '0'));
记得z数据类型转化，以及+'0',还有最后的tag /= 2;


```
class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        int la = a.length() - 1;
        int lb = b.length() - 1;
        string c = "";
        int tag = 0;
        //条件tag == 1即为首位1的放置
        while(tag == 1 || la >= 0 || lb >= 0)
        {   
            if(la >= 0 && a[la--] == '1')
                tag++;
            if(lb >= 0 && b[lb--] == '1')
                tag++;
            c.insert(0,1,(char)(tag % 2 + '0'));
            tag /= 2;
        }
        return c;
    }
};
```
