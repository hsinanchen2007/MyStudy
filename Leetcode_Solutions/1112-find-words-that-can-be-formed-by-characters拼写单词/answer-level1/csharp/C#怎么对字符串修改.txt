对于参数为一个字符串的情况，C#不同于C/C++，不允许对字符串修改，但是我们可以调用C#字符串方法实现修改字符串

```c# []
while (tempI.Length > 0)  //保证在字母表中找到每个单词的字母
{
    for (int n = 0; n < temp.Length; n++)
    {
        if (tempI[0] == temp[n])    //单词的字母在字母表中
        {
            //C#中字符串是只读的
            tempI = tempI.Remove(0, 1); //移除掉单词的字母
            temp = temp.Remove(n, 1);
            temp = temp.Insert(n, "1");
            break;
        }
    }
    if (tempI.Length != i.Length - lessCir++ - 1)
        break ;     //如果单词中靠前的字母都没有找到，就肯定是不在字母表中的单词
}
```

