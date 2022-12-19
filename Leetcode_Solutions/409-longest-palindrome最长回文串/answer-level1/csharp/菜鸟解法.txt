### 解题思路
此处撰写解题思路

### 代码

回文串中只能有一个单数字母。剩下字母都应该是双数的。

```csharp
public class Solution {
    public int LongestPalindrome(string s) 
    {
       Dictionary<char,int> dir=new Dictionary<char,int>();

       for(int i=0;i<s.Length;i++)
       {
           if(dir.ContainsKey(s[i]))
           {
               dir[s[i]]++;
               continue;
           }
           dir.Add(s[i],1);
       }

       int num=0;
       //是否已经包含一个奇数了
       bool isHaveOddNumber=false;
       foreach(KeyValuePair<char,int> pair in dir)
       {
           //说明是偶数
           if(pair.Value%2==0)
           {
               num+=pair.Value;
           }
           //说明是奇数
           else
           {
               //字符串里面只能有一个单数
               //如果没存在
             if(!isHaveOddNumber)
             {
                num+=pair.Value;
                isHaveOddNumber=true;
             }
             // 如果已经存在一个单数
             else
             {
                num+=pair.Value-1;
             }
           }
       }
       
     
     return num;


    }
}
```