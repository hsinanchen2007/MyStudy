### 解题思路
看到一个回溯模板，之前都没注意过，然后自己发现跟模板写的基本一样，mark下来

### 代码
```java []
class Solution {
    // 做完之后出现的问题记录：根据println看出，已经得到答案，但是实际输出却是[[2],[7]]，可能是因为list递归的内存等问题
    // 28行位置解决此问题
    List<List<Integer>> res;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        // 深度优先搜索加回溯？
        res = new ArrayList<>();
        // 排序后，res按从小到大返回，意思是：如果搜索到最后一个值，那只可能存在这个值
        Arrays.sort(candidates);
        int n = candidates.length;

        for (int i = 0; i < n; ++i) {
            // 以每个为跟开始搜索
            List<Integer> list = new ArrayList<>();
            list.add(candidates[i]);
            dfs(candidates, i, n, 1, target, list, candidates[i]);
        }

        return res;
    }

    // index 表示需要从第几位开始搜索，只能向后不能向前    n: candidates数   m：list元素数
    void dfs(int[] candidates, int index, int n, int m, int target, List<Integer> list, int listSum) {
        if (listSum == target) {
            // 重新申请一块内存空间，实测可以，。    原方法的话，再add到res里就是最初的值
            //  正确的简洁的方法
            res.add(new ArrayList<>(list));
            /*  正确的麻烦的方法
            List<Integer> oneOfRes = new ArrayList<>();
            for (int i = 0; i < list.size(); ++i) oneOfRes.add(list.get(i));
            res.add(oneOfRes);*/
            /*  错误的方法
            res.add(list);*/
            return;
        }
        if (listSum > target) return;
        for (int i = index; i < n; ++i) {
            list.add(candidates[i]);
            dfs(candidates, i, n, m+1, target, list, listSum + candidates[i]);
            list.remove(m);
        }
    }
}
```
```python []
# 回溯模板
def backward():
    
    if (回朔点）：# 这条路走到底的条件。也是递归出口
        保存该结果
        return   
    
    else:
        for route in all_route_set :  逐步选择当前节点下的所有可能route
            
            if 剪枝条件：
                剪枝前的操作
                return   #不继续往下走了，退回上层，换个路再走
            
            else：#当前路径可能是条可行路径
            
                保存当前数据  #向下走之前要记住已经走过这个节点了。例如push当前节点
        
                self.backward() #递归发生，继续向下走一步了。
                
                回朔清理     # 该节点下的所有路径都走完了，清理堆栈，准备下一个递归。例如弹出当前节点
```
