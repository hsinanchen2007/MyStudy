### 解题思路
使用二维数组及z字型周期性，值得注意的是周期是numRows-1而不是numRows. 看了下官方的答案，更简洁也更有效率。

### 代码

```csharp
public class Solution {
    public string Convert(string s, int numRows) {

            if(numRows<=1||s.Length==1)
            {
                return s;
            }
            char[,] result = new char[numRows, (s.Length / (2*numRows-2) +1)*(numRows-1)];

            int i = 0, j = 0;

            for (int k = 0; k < s.Length; k++)
            {
                if(j%(numRows-1)==0)
                {
                    result[i, j] = s[k];

                    if (i == numRows - 1)
                    {
                        j++;
                        i = 0;
                    }
                    else
                    {
                        i++;
                    }
                }
                else
                {
                    result[numRows -1- j % (numRows-1), j] = s[k];
                    j++;
                }
            }

            string resultString = "";
            for (i = 0; i < result.GetLength(0); i++)
            {
                for (j = 0; j < result.GetLength(1); j++)
                {
                    if (result[i, j] != '\0')
                    {
                        resultString += result[i, j];
                    }
                }
            }

            return resultString;
    }
}
```