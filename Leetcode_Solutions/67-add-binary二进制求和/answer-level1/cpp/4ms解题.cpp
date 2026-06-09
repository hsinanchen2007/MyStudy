void swap(string& x,string& y)
{
    string temp=x;
    x=y;
    y=temp;
}

class Solution {
public:
        string addBinary(string a, string b) {
        int ai;
        int bi;
        int than = 0;
        if (a.size() < b.size())
        {
            //交换
            swap(a, b);
        }
        //始终让a更长
        int i;
        int j;
        for (i = a.size() - 1, j=b.size() - 1; i >= 0; i--,j--)
        {
            ai = (int)a[i]-(int)'0';
            if (j <0)
                bi = 0;
            else
                bi = (int)b[j] - (int)'0';
            if (ai + bi + than >= 2)
            {
                a[i] = (ai + bi + than-2)+'0';
                than = 1;//有进位
            }
            else
            {
                a[i] = (ai + bi + than) + '0';
                than = 0;
            }
        }
        //在最高位
        if (than)
            a.insert(0, 1, '1');
        return a;
    }
};

要点：
1.字符串a b长度不一样，不好计算。
   解决方法： 始终让a为长的字符串，b不够位前面补零

2.int 与 char 互转
  int—>char   char=intnum+'0'
  char->int   int=int(char-'0');

3.进位表示
  可设置bool变量，than=1，表示有进位，than=0，无进位
  result[i]=a[i]+b[i]+than
 