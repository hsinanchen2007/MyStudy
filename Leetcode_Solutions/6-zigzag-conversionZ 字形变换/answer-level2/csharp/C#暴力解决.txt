### 解题思路
本题乍一看无从入手，仔细分析题意，我们举一个行数为4的例子（方便起见我用下标代替字母）：
1     7        13
2   6 8     12
3 5   9  11
4     10   
我们发现1到6和7到12是一样的形状，所以我们只需分析前6个即可。
通过我们可以得到以下规律：字母排列方式每（n*2-2）个是一个循环（第一列有n个，第一个斜着的边上有n个，但是斜边最后一个不属于本次循环，左下角的算了两次，所以减2）。
接下来，我们发现，字符串中下标模（n*2-2）所得结果为0的都在第一行，为1的在第二行，为2的在第三行。。。。为（n*2-2）-1的在第二行。于是我们就可以得到一种输入字符与输出字符下标的关系。

### 代码

```csharp
public class Solution {
    public string Convert(string s, int numRows) {
        int m = 2 * numRows - 2;
        int i = 0;
        string r = "";
        if (numRows == 1)
            return s;
        while(i <= m - i)
        {
            for(int j = 0; j < s.Length; j++)
            {
                if (j % m == i || j % m == m - i)
                {
                    if(i != m / 2)
                    {
                        r = r + s[j];
                    }
                    else if(j % m != 2 * i)
                    {
                        r = r + s[j];
                    }
                }
            }
            i++;
        }
        return r;
    }
}
```