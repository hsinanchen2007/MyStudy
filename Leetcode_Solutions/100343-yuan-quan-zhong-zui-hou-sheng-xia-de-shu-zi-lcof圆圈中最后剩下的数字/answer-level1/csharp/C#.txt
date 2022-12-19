### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
      public int LastRemaining(int n, int m) {
        int p=0;
	for(int i=2;i<=n;i++)
	{
		p=(p+m)%i;
	}
    return p;
    }

}

```