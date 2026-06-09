### 解题思路
此处撰写解题思路

1、判断是正是负
2、转成字符调用字符的Reverse()方法，
3、在转回int

### 代码

```csharp
public class Solution {
    public int Reverse(int x) {
        string strX =x.ToString();
        bool isMinus = x < 0 ? true : false;
        string str = isMinus ? strX.Substring(1, strX.Length - 1) : strX;
        var items = str.Reverse();
        string reu = string.Empty;
        foreach (var item in items)
        {
            reu += item;
        }

        return isMinus ? int.TryParse(reu, out int xx) ? -int.Parse(reu) : 0 : int.TryParse(reu, out int xxx) ? int.Parse(reu) : 0;
    }
}
