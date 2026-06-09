### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
  public  int CalPoints(string[] ops)
        {
            int score = 0;
            Stack<string> stack = new Stack<string>();
            for (int i = 0; i < ops.Length; i++)
            {
                switch (ops[i])
                {
                    case "C":
                        score = score - int.Parse(stack.Pop());
                        break;
                    case "+":
                        int first = int.Parse(stack.Pop());
                        int second=  int.Parse(stack.Pop());
                        score =score+first+second;
                        stack.Push(second.ToString());
                        stack.Push(first.ToString());
                        stack.Push((first+second).ToString());
                        break;
                    case "D":
                        int previousRound= int.Parse(stack.Pop());
                        int two = previousRound*2;
                        score += two;
                        stack.Push(previousRound.ToString());
                        stack.Push(two.ToString());
                        break;

                    default:
                        score += int.Parse(ops[i]);
                        stack.Push(ops[i]);
                        break;
                }
            }
            return score;
    }
}
```