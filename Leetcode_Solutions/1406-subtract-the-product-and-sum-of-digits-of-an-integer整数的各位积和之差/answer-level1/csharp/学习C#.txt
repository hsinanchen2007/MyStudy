### 解题思路
动态数组定义 `List<int> nums = new List<int>(0);`
动态数组添加 `nums.Add()`
动态数组大小`nums.Count`
### 代码

```csharp
public class Solution {
    public int SubtractProductAndSum(int n) {
        List<int> nums = new List<int>(0);
        while(n!=0){
            nums.Add(n%10);
            n /=10;
        }
        int a= 0 ;
        int m = 1;
        foreach(int i in nums){
            a+=i;
            m*=i;
        }
        return m-a;
    }
}
```