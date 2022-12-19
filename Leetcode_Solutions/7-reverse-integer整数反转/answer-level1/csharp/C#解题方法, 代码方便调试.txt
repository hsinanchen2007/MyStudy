### 解题思路
思路在代码注释里
### 代码

```csharp
public class Solution {
    public int Reverse(int x) {
        int y = 0, tem = 0;
        while (x != 0) {
            //1.取个位, 第二次进来要进位
            int a = x % 10;
            y = y * 10 + a; //当x=int.MaxValue时, 且x降到个位时, y*10会溢出

            //溢出后的y降位后不会等于上一次的结果(tem)
            int b = y / 10;
            if (tem != b) { return 0; }

            //保存本次的结果
            tem = y;

            //2.降位
            x /= 10;
        }
        return y;
    }
}
```