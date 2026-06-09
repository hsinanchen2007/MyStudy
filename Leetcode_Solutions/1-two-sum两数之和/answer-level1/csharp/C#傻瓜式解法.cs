### 解题思路
执行用时 :
672 ms, 在所有 csharp 提交中击败了12.53%的用户
内存消耗 :29.8 MB, 在所有 csharp 提交中击败了6.75%的用户

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] arr, int num) {
        int a = -1, b = -1, d = 0;
        //a存第一个的下标
        //b存第二个的下标
        //d用来做第二次循环时比较的变量
        for (int i = 0; i < arr.Length; i++)
        { 
            a = i;//储存下标
            d = num - arr[i];
            for (int s = 0; s < arr.Length; s++)
            {
                if (s==i) {//避免元素重复使用
                    continue;
                }
                else if (d == arr[s])
                {
                    b = s;//获取到第二个下标
                    break;
                }
            }
            try//避免b为—1时报错
            {
                if (arr[a] + arr[b] == num)
                {
                    break;
                }
            }
            catch { }
        }
        int[] ar = new int[2];
        ar[0] = a; ar[1] = b;
        return ar;
    }
}
```