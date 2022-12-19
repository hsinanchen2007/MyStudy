### 解题思路
转成字符串数组，使用Array类的Reverse方法颠倒数据，
然后使用int.TryParse判断是否溢出。
### 代码

```csharp
public class Solution {
    public int Reverse(int x) {
        string aa = x+"";
        string bb = aa.Substring(0,1);
        string str2 = "";
        if (bb == "-")
            {
                string cc = aa.Substring(1, aa.Length - 1);
                char[] ch = cc.ToArray();
                Array.Reverse(ch);//使用Array类的Reverse方法颠倒数据
                str2 = test(ch);
                int newint = -1;
                bool isok = int.TryParse(str2, out newint);
                if (isok)
                {
                    return Convert.ToInt32(bb + str2);
                }
                else
                {
                    return 0;
                }
               
            }
            else
            {
                char[] ch = aa.ToArray();
                Array.Reverse(ch);//使用Array类的Reverse方法颠倒数据
                str2 = test(ch);
                int newint = -1;
                bool isok = int.TryParse(str2,out newint);
                if (isok)
                {
                    return Convert.ToInt32(str2);
                }
                else
                {
                    return 0;
                }
                
            }
        return Convert.ToInt32(str2);
    }
    public string test (char [] cc)
        {
            string result = "";
            foreach (var item in cc)
            {
                result += item;
            }
            return result;
        }
}
```