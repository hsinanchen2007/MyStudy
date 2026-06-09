想法：
    这一题的难点在于数字可以无限制重复，但是又要避免解集中出现重复,由此想到累加的下一次要从自身的index开始。
    需要不断的迭代出多个list，第一反应就是搜索，然后选择dfs深度优先搜索。
思路过程：
1、设置出口：用一个list存放之前的数字，sum代表还需要的值，如果sum等于当前值则表示list+当前值，表示获得一个结果。
2、找到dfs进入下一层的情况：对每一个数遍历，分为3种情况：
 2.1、当前数字等于sum，找到一个结果list，存放起来。
 2.2、当前数字偏小，那么就加入list，进入下一层，将sum修改。
      为了避免重复，下一层从自身坐标之后的数字。
      数字允许取多次，则从自身坐标开始。
 2.3、当前数字偏大，那么由于我们经过了排序（如代码实现处理），则表示后面的肯定都是偏大，可以剪枝跳出这个循环。
      若不经过事先排序，则与2.2一样继续往下一层遍历即可。
3、考虑到list的引用关系，我们不断的迭代一个list，实际存放的时候则都要新建一个list存放。

以上的思路就是一个深度优先搜索的过程。
```
List<List<Integer>> allResultList = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (target <= 0) {
            allResultList.add(new ArrayList<>());
        }
        //先排序，排序后可以加剪枝
        Arrays.sort(candidates);
        dfs(new ArrayList<>(), candidates, 0, target, 0);
        return allResultList;
    }


    public void dfs(List<Integer> list, int[] candidates, int sum, int target, int start) {
        for (int i = start; i < candidates.length; i++) {
            list.add(candidates[i]);
            if ((sum + candidates[i]) == target) {
                //此时tmpList 满足
                List<Integer> tmpList = new ArrayList<>(list);
                allResultList.add(tmpList);
            } if ((sum + candidates[i]) < target) {
                dfs(list, candidates, sum + candidates[i], target, i);
            } else {
                list.remove(list.size() - 1);
                //(sum+candidates[i]) > target,因为数组有序，后面一定不满足
                break;
            }
            list.remove(list.size() - 1);

        }
    }
```
![image.png](https://pic.leetcode-cn.com/516267b2e4b6352ee938810942d721622b6d5580ff4c4ff0db731dd260899f50-image.png)
