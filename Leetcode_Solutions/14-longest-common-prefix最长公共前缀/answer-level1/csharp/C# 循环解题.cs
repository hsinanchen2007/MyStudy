### 解题思路
此处撰写解题思路
我的思路是从第一条开始对比，一旦对比失败，就返回
### 代码

```csharp
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        //基础条件
        if (strs.Length == 1) return strs[0];
        if (strs.Length == 0) return "";
        // 列表的第一条拿出来，做对比
        char[] first = strs.First().ToArray(); 
        string res = string.Empty; 
        for (int i = 0; i < first.Length; i++)
        {
            bool b = true;
            for (int j = 1; j < strs.Length; j++)
            {
                // 一旦失败就没有再往下比的必要，直接跳出来
                if (i >= strs[j].Length)
                {
                    b = false;
                    break;
                }
                b = strs[j][i]==first[i] ? true : false;
                if (!b)
                    break;
            }

            if (b)
            {
                //记录公共前缀
                res += first[i];
            }
            else
            {
                break;
            }
        }
        return res;
    }
}
```