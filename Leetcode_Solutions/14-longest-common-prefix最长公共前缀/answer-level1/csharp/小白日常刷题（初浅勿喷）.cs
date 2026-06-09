### 解题思路
首先我们的题意是一个字符串数组里面多个字符 要提取公共前缀 
首先我们先排除掉数组长度为0 和 1的情况 

然后以第一个字符串为基础 

依次跟后面的比较 



### 代码

```csharp
public class Solution {
  public string LongestCommonPrefix(string[] strs)
        {

            if (strs.Length == 1)
                return strs[0];
            else if (strs.Length == 0)
                return "";
            StringBuilder stringBuilder = new StringBuilder(strs[0]);
            int index = 1;
            int go = 0;
            while (index < strs.Length)//这儿相当于一个循环 
            {
                go = 0;//比较下标
                while(go< stringBuilder.Length &&go< strs[index].Length)
                {
                    if ( stringBuilder[go] == strs[index][go])
                    {
                        go++;
                    }
                    else
                    {
                        if (go == 0)
                        {
                            go = -1;
                        }
                        break;//跳出
                    }
                }
                if (go == -1)
                {
                    return "";//跳出
                }
                else
                {
                    if (go  >= strs[index].Length)
                        stringBuilder = new StringBuilder(strs[index]);
                    else
                        stringBuilder = new StringBuilder(strs[index].Substring(0, go));
                }
                index++;
            }
            return stringBuilder.ToString();
        }
}
```