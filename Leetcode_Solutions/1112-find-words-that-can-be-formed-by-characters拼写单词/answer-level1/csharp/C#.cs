### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int CountCharacters(string[] words, string chars) {
            int[] list = new int[26];
            for (int i = 0; i < chars.Length; i++)
            {
                list[chars[i] - 97]++;//(int)'a' == 97,(int)'z' == 122
            }
            int ans = 0;
            foreach (string w in words)
            {
                bool isOk = true;
                int[] temp = new int[26];
                for (int i = 0; i < w.Length; i++)
                {
                    if (list[w[i] - 97] > 0) //chars中包含的字符
                    {
                        temp[w[i] - 97]++;
                        if (temp[w[i] - 97] > list[w[i] - 97]) 
                        {
                            //字符在单词中出现次数大于chars中出现次数
                            isOk = false;
                            break;
                        }
                    }
                    else //出现chars中不包含的字符，直接跳过
                    {
                        isOk = false;
                        break;
                    }
                }
                if (isOk)
                {
                    ans += w.Length;
                }
            }
            return ans;
    }
}
```