### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int SumNums(int n) {
            //看到题目要求的第一反应是总结出求和公式并采用位运算
            int count =(int) Math.Pow(n, 2) + n;
            return count >>1;
    }
}
```