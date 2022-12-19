### 解题思路
做这道题还是缺了点脑子，没有考虑到超时。
但是收获就是发现了C# 的数组切片表示方法
`int[] slice = arr.Skip(StartNum).Take(arr.Length).ToArry();`
`arr = [1,2,3,4,5]`
`arr.Skip(1).Take(2).ToArray();` 得到`[2,3]`;
`arr.Skip(1).ToArray();`得到`[2,3,4,5]`;

### 代码

```csharp
public class Solution {
    public int[] ReplaceElements(int[] arr) {
        int len = arr.Length;
        int[] res = new int[len];
        res[len-1] = -1;
        for(int i = len-2;i>-1;i--){
            if(res[i+1]<arr[i+1]) res[i] = arr[i+1];
            else res[i] = res[i+1];
        }
        return res;
        //answer1  超时
        // for(int i = 0;i<arr.Length;i++)
        // {
        //     if(i!=arr.Length-1)
        //     arr[i] = arr.Skip(i+1).ToArray().Max();
        //     else arr[i] = -1;
        // }
        // return arr;
        // test
        // Console.WriteLine(arr.Max());
        // Console.WriteLine(arr.Skip(1).ToArray().Max());
        // return new int[] {0};
    }
}
```