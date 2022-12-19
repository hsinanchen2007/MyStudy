```
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string c = "";
        bool carry = 0;//是否进位
        char x, y;
        int la = a.size(), lb = b.size();
        for (int i = la - 1, j = lb - 1; i >= 0 || j >= 0; --i, --j)//for循环从每个字符串的最后一位开始遍历
        {
            x = i >= 0 ? a[i] : '0';//x,y如果下标越界就变成char类型的'0'
            y = j >= 0 ? b[j] : '0';
            if (x == y)//x=y要么都为'0'要么都为'1'
            {
                if (!carry)//无需要进位的情况
                {
                    if (x != '0')//x,y都为'1'的时候，需要进位
                        carry = 1;
                    c = "0" + c;//因为x=y的时候加起来必定=0，所以给c这个string开头+'0'
                }
                else//要进位
                {
                    carry = 0;//先消去进位标志
                    if (x != '0')//如果x=y=1那又要进位，再赋值进位标志
                        carry = 1;
                    c = "1" + c;//不管如何，x+y必定为0，再加前面进位的1就是1
                }
            }
            else//这个就是xy不等的情况
            {
                if (!carry)
                    c = "1" + c;//无进位，x+y=1
                else
                    c = "0" + c;//有进位，x+y=1，再加进位1，为0，还要进位，不用消除进位标志
            }
        }//循环结束，再看看进位标志是否为0，不是0，说明前面还要再加1个1
        if (carry)
            c = "1" + c;
        return c;
    }
};
```