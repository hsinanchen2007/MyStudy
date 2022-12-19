### 解题思路
这个C#居然自带的排序跟Reverse一样直接把原数组改变，都没法赋值给新的数组的，只能先复制一份了
### 代码

```csharp
public class Solution {
    public int HeightChecker(int[] heights) {
        var nh = new List<int>(0);
            foreach(var n in heights){
                nh.Add(n);                    
            }
            Array.Sort(heights);
            int res = 0;
            for(int i = 0;i<heights.Length;i++){
                    if(heights[i]!=nh[i]) res++;
            }
            return res;
    }
}
```