# 实现代码
```csharp
public IList<int> GrayCode(int n)
{
    IList<int> list = new List<int> { 0 };
    int len;
    for (int i = 0; i < n; i++)
    {
        len = list.Count;//记录之前元素数量
        for (int j = len - 1; j >= 0; j--)
        {
            list.Add((int)(list[j] + Math.Pow(2, i)));//对之前元素进行逆序复制并加上“1”
        }
    }
    return list;
}
```
通过百度之后明白了它的内容，并了解了递归转换格雷码的方法，详细可点击[格雷码及其转换方式](https://baike.baidu.com/item/%E6%A0%BC%E9%9B%B7%E7%A0%81/6510858?fr=aladdin)查看。