### 解题思路
每个物品可以重复拿，那么每次递归都可以选择上次选择的物品，以及剩下的物品。当拿到第n个物品的时候不能拿第n个物品之前的物品
因为前面物品的各种排列已经计算过了。
开始排序物品可以优化搜索过程。
如果排序后第一个物品就大于target那么不必要继续搜索。

### 代码

```csharp
public class Solution {
    public List<IList<int>> ans = new List<IList<int>>();
    public List<int> temp= new List<int>();
    public int len;
    int[] a;
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        len = candidates.Length;
        if(len == 0) return ans;
        Array.Sort(candidates);
        a = candidates;
        if(candidates[0] > target) return ans; 
        dfs(0,target,0);
        
        return ans;
    }

    public void dfs(int start,int target, int sum) {
        if(sum > target) return;
        if(target == sum) {
            Console.WriteLine(temp.Count);
            List<int> b = new List<int>();
            foreach(var t in temp) {
                b.Add(t);
            }
            ans.Add(b);
            return ;
        } 

        for(int i = start; i < len; i ++) {
            temp.Add(a[i]);
            dfs(i,target,sum+a[i]);
            temp.RemoveAt(temp.Count-1);
        }


    }

}
```