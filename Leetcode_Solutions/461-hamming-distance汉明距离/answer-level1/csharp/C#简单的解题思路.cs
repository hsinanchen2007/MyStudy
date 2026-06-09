### 解题思路
直接进行异或然后统计1出现的次数，即为汉明码距离。

### 代码

```csharp
public class Solution {
    public int HammingDistance(int x, int y) {
        string a = System.Convert.ToString(x^y, 2);
       //string b = System.Convert.ToString(a,2);
        int i =0;
        foreach(char item in a){
            if(item == '1') ++i;
        }
        return i;
    }
}
```