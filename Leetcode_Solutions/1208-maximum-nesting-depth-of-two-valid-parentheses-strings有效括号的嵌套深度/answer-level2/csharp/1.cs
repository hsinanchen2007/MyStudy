### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] MaxDepthAfterSplit(string seq) {
        int[] res = new int[seq.Length];
        List<int> right = new List<int>();
        List<int> left = new List<int>();

        for(int i = 0; i < seq.Length; i++)
        {
            var currentChar = seq[i];
            if(currentChar == '(')
            {
                left.Add(i);
            }
            else
            {
                right.Add(i);
            }
        }

        for(int i = 0; i < right.Count; i+=2)
        {
            res[right[i]] = 1;
            res[left[i]] = 1;
        }
        
        return res;
    }
}

```