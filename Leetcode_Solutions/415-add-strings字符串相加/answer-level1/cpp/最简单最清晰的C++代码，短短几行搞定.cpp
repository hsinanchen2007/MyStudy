```
class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        int ln1 = num1.length() - 1;
        int ln2 = num2.length() - 1;
        int carry = 0;
        //定义一个空字符串，一边后面插入数字字符
        string c = "";
        while(carry == 1 || ln1 >= 0 || ln2 >= 0)
        {
            //z一定要把num1和num2分开考虑，防止出现因两数的位数不同而出现错误
            int x = ln1 < 0 ? 0 : num1[ln1--] - '0';
            int y = ln2 < 0 ? 0 : num2[ln2--] - '0'; 
            //记得此处转换为char型，以及后面加'0'
            c.insert(0,1,char(x+y+carry) % 10 +'0');
            //carry表示进位
            carry = (x+y+carry)/10;
        }
        return c;
    }
};
```
