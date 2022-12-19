### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public  IList<string> FizzBuzz(int n)
        {
            List<string> num = new List<string>();
            for (int i = 1; i <= n;i++)
            {
                if(i % 3 == 0 && i % 5 == 0){
                    num.Add("FizzBuzz");
                   
                }
                else if(i%5==0){
                    num.Add("Buzz");
                }
                else if (i % 3 == 0)
                {
                     num.Add("Fizz");
                }
                else
                {
                    num.Add(i.ToString());
                }

            }

            return num;
        }

}
```