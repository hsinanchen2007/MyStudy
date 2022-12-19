### 解题思路
此处撰写解题思路

-- 玄学的排名，忽高忽低各位见笑哈
执行用时 :
92 ms, 在所有 C# 提交中击败了97.11%的用户
内存消耗 :
24 MB, 在所有 C# 提交中击败了41.04%的用户

我是leetcode新手
一些特殊情况我也不会操作，就直接用if来判断了
### 代码

```csharp
public class Solution {
    public string CountAndSay(int n) {
        string returnStr = "1";
        if(n == 1)
        {
            return "1";
        }
        for (int i = 1; i < n; i++)
        {
            returnStr = GetString(returnStr);
        }

        return returnStr;
    }

    private static string GetString(string str)
    {

        StringBuilder sb = new StringBuilder();
        char num ;
        int time = 1;
        int j = 0;


        if(str == "1")
        {
            return "11";
        }

        for (int i = 0; i < str.Length; i++)
        {
            j = i;
            num = str[i];
            time = 1;

            if(i == str.Length - 1)
            {
                sb.Append("1");
                sb.Append(num);
                break;
            }

            while(str[j+1] == str[i])
            {
                time++;
                j++;
                if(j== str.Length-1 )
                {
                    break;
                }
            }
            Console.WriteLine(time + "个" + num);
            sb.Append(time);
            sb.Append(num);
            i = j ;

        }
        return sb.ToString();
    }
}
```