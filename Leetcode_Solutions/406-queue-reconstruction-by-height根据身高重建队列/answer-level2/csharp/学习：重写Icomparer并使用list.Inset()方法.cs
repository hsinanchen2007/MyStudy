### 解题思路
跟官方题解思路一样，这里给出C#实现的代码

### 代码

```csharp
public class Solution {
    public int[][] ReconstructQueue(int[][] people) {
        Array.Sort(people,new TestIComparer());
        List<int[]> res = new List<int[]>();
        foreach(var item in people){
            res.Insert(item[1],item);
        }
        return res.ToArray();
    }
}
public class TestIComparer:IComparer<int[]>{
    public int Compare(int[] a,int[] b){
        if(a[0]!=b[0]){
            return b[0]-a[0];
        }else{
            return a[1]-b[1];
        }
    }
}
```