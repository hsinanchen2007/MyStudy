### 解题思路
1.利用C#先分组，然后在筛选组里面只有一个元素的

### 代码

```csharp
public class Solution {
    public int SingleNonDuplicate(int[] list) {
           if (list==null)
            {
                throw  new ArgumentNullException();
            }

            var listbu=list.GroupBy(g => g);
            var model=listbu.Where(t => t.Count() == 1);
            
            var num= model.FirstOrDefault()?.Key;
            return num??0;
    }
}
```