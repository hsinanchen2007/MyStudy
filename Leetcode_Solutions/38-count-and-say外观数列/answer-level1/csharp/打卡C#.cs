### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public string CountAndSay(int n) {
StringBuilder builder = new StringBuilder ();
			string curNum = "1";
			int count = 1;

			for (int j = 1; j < n; j++)
			{
				builder.Clear ();
				count = 1;
				for (int i = 1; i < curNum.Length; i++)
				{
					if (curNum[i] == curNum[i - 1])
					{
						count++;
					}
					else
					{
					
						builder.Append ($"{count}{curNum[i - 1]}");
						count = 1;
					}
				}
				builder.Append ($"{count}{curNum[curNum.Length - 1]}");

				curNum = builder.ToString ();
			}

			return curNum;

    }
}
```