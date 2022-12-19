### 解题思路
此题与 组合总和1有相似之处，不同在于一个元素只能选一次，那么我们dfs的时候下一层就不能选择上一层的元素。这样就保证了解的完整。
但是搜索出的解有重复，如何去除？原因是有重复的元素，我们将数组排序，每层向下递归时必须保证选择的元素与之前选择过的元素做出了变化，这样就可以避免重复，原因很简单，比如1 1 3 4 5，第一层如果从1开始，那么它将搜索1 与后面4个元素的所有情况，我们可以拆分为 1 与 3 4 5，1 与 1 3 4 5的所有情况之和，也就是有无第二个1，如果从第一层搜索完毕，我们还选择第二个1的话就是搜索1 与 3 4 5的解的空间与上面有重复，所以我们不能在一层中选择与之前相同的值进行搜索。

### 代码

```csharp
public class Solution {
    public List<IList<int>> ans = new List<IList<int>>();
    public List<int> temp= new List<int>();
    public int len;
    int[] a;
    public IList<IList<int>> CombinationSum2(int[] candidates, int target) {
        len = candidates.Length;
        if(len == 0) return ans; //特判
        Array.Sort(candidates); //优化手段 去重手段
        a = candidates;
        if(candidates[0] > target) return ans; //剪枝
        dfs(0,target,0);
        
        return ans;
    }

    public void dfs(int start,int target, int sum) { //start保证一个位置只能选择一次
        if(sum > target) return; //边界
        if(target == sum) { //捕获答案
           // Console.WriteLine(temp.Count);
            List<int> b = new List<int>();
            foreach(var t in temp) {
                b.Add(t);
            }
            ans.Add(b);
            return ;
        } 

        for(int i = start; i < len; i ++) {
            if(a[i] > target) return ; //剪枝
            if(i > start && a[i] == a[i-1])continue; //去重
            temp.Add(a[i]);
            dfs(i+1,target,sum+a[i]);
            temp.RemoveAt(temp.Count-1); //回溯
        }


    }

}
```