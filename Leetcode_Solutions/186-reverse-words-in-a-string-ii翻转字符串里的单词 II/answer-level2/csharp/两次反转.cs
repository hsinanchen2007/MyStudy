### 解题思路
参考高赞的题解思路，先反转所有的单词，再反转整个数组

### 代码

```csharp
public class Solution {
    public void ReverseWords(char[] s) {
       int i = 0; int j =0;
       for(;j < s.Length; j++)
       {
           if(s[j] !=  ' ')
           {
               continue;
           }
           Reverse(s, i, j - 1);
           i = j + 1;
       }

       Reverse(s, i, j -1);
       Reverse(s, 0, s.Length - 1);
    }

    private void Reverse(char[] s, int left, int right)
    {
        while(left < right)
        {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
}
```