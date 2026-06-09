想法还是比较简单的，用一个字符串记录每一个数字的二进制表示，然后同时记录1的个数
比如最开始为0，那么字符串就为'0',然后就加一变成了'1',再加1，就变成'10'
'11'、'100'....就不断记录1的个数，然后存储就行了。
```
class Solution {
    string numstr;
    int count1;//1的个数
    void add1()
    {
        int i;
        bool sign = true;
        for(i =0;i < numstr.length();i++)
        {
            if(numstr[i] == '0')
                break;
        }
        if(i == numstr.length())//全为1
        {
            for(i = 1;i < numstr.length();i++)
            {
                numstr[i] = '0';
            }
            numstr += '0';
            count1 = 1;
            return ;
        }
        i = numstr.length()-1;
        while(sign)
        {
            if(numstr[i] == '0')
            {//原来为0的位变成了1，所以count1加一
                numstr[i] = '1';
                count1++;
                sign = false;
            }
            else
            {//为1的位变成了0，所以count1加一
                numstr[i] = '0';
                count1--;
            }
            i--;
        }
    }
public:
    vector<int> countBits(int num) {
        numstr = "0";
        vector<int> re;
        int i;
        count1 = 0;
        for(i = 0;i <= num;i++)
        {
            re.push_back(count1);
            add1();//模拟二进制的加一操作，并且改变count1的值
        }
        return re;
    }
};
```
