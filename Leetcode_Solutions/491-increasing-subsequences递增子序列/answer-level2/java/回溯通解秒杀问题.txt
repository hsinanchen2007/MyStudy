### 解题思路
本题可使用DFS模版进行解答，本题与子集Ⅱ问题类似，只需要多增加两个判断条件即可
框架：
```
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

for 选择 in 选择列表:
    做选择
    backtrack(路径, 选择列表)
撤销选择
```

由于最终结果可能有重复，因此使用HashSet首先对结果进行去重，以本题的例子[4, 6, 7, 7]进行说明
因为对于子集Ⅱ问题来说，可以通过对原始数组进行排序后，通过条件
```java
if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) {
        continue;
    }
```
进行去重，因为下标为0和2的组合与下标为0和3的组合是一样的，但本题不能对原始数组进行修改，
所以本题可以通过HashSet对结果进行去重。

### 代码

```java
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> temp = new ArrayList<>();
    Set<List<Integer>> s = new HashSet<>();
    public List<List<Integer>> findSubsequences(int[] nums) {
        if (nums.length == 0) {
            return res;
        }
        int[] visited = new int[nums.length];
        dfs(nums, 0, visited);
        return new ArrayList<>(s);
    }

    public void dfs(int[] nums, int depth, int[] visited) {
        // 本题中该if可以省去
        if (depth == nums.length) {
            return;
        }      
        for (int i = depth; i < nums.length; i++) {
            // 如果该元素访问过，直接跳过
            if (visited[i] == 1) {
                continue;
            }
            // 当temp的容量为0，或者temp的容量大于0且新加入的元素大于temp的最后一个元素，才将新元素加入temp
            if (temp.size() == 0 || nums[i] >= temp.get(temp.size() - 1)) {
                visited[i] = 1;
                temp.add(nums[i]);
                if (temp.size() >= 2) {
                    s.add(new ArrayList<>(temp));
                }
                dfs(nums, i + 1, visited);
                // 撤销选择，即移除新加入的元素，并将访问标志设为未访问。
                temp.remove(temp.size() - 1);        
                visited[i] = 0;
            }
            
        }
    }
}
```