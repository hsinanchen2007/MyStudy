### 解题思路
使用DFS深度优先的思想采用递归的方式
类似于二分法，分左右两种情况解决
约束是**左括号必须多余或等于右括号**且**小于等于输入的数值**

### 代码

```csharp
public class Solution {
    List<string> list = new List<string>();
    public IList<string> GenerateParenthesis(int n) {
            StringBuilder str = new StringBuilder();
            generatingLeft(1, 0, n,str);
            return list;
    }
    public void generatingLeft(int x,int y,int n,StringBuilder str)
        {
            if(x<y || x>n || y > n)
            {
                return;
            }
            StringBuilder str1 = new StringBuilder();
            str1.Append(str);
            str1.Append("(");
            generatingLeft(x + 1, y, n, str1);
            generatingRight(x, y + 1, n,str1);
            if (x == n && y == n)
            {
               list.Add(str1.ToString());
            }
        }

        public void generatingRight(int x, int y, int n, StringBuilder str)
        {
            if (x < y || x > n || y > n)
            {
                return;
            }
            StringBuilder str2 = new StringBuilder();
            str2.Append(str);
            str2.Append(")");
            generatingLeft(x + 1, y, n, str2);
            generatingRight(x, y + 1, n, str2);
            if (x == n && y == n)
            {
                list.Add(str2.ToString());
            }
        }
}
```