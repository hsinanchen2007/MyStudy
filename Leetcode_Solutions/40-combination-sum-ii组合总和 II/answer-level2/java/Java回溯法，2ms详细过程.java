以{1, 1, 2, 5, 6, 7}，target = 8 为例模拟一下解题流程
首先排个序，是为了以后能方便的剪枝以及跳过重复的解

1. 遍历数组，进行累加，若小于 8 就继续遍历，得到 [1, 1, 2]
2. 下一个 5 添加进来后就大于 8 了，所以直接 break 这次遍历，并从列表中退出 2，然后从2的下一个元素继续遍历，得到 [1, 1, 5]
3. 下一个 6 添加进来后大于 8，所以去掉 5，从将5 后一个元素继续得到 [1, 1, 6]，判断等于 8，所以保存该解，因为已经排好了序，所以后面的元素不用再看了，就 break这次循环
4. 这时列表中只有 [1, 1]， 将第二个 1 退出，从它的后一个元素开始遍历，得到 [1, 2, 5]，保存该解并break这次循环
5. 退出2，从它的下一个元素开始，得到[1, 5]
6. 下一个 6 添加进来后大于 8，所以去掉5，添加6，得到[1, 6]
7. 下一个 7 添加进来后大于 8，所以去掉6，添加7，得到[1, 7]，保存该解并break这次循环
8. 退出1，从它下一个元素开始，因为下一个元素还是1，所以跳过它，再下一个元素是2，于是从2开始得到[2, 5]
9. 下一个 6 添加进来后大于 8，所以去掉5，添加6，得到[2, 6]，保存该解并break这次循环
10. 退出2，从它下一个元素 5 开始，得到 [5]
11. 下一个 6 添加进来后大于 8，所以去掉5，添加6，得到 [6]
12. 下一个 7 添加进来后大于 8，所以去掉6，添加7，得到 [7]

7后没有元素了，回溯结束。大概就是这么个图（随手一画，勉强看吧，，），每个格子和上面的步骤一一对应
![B65A39{CDY(D((W~DS5K$1A.png](https://pic.leetcode-cn.com/ba49591ed145e38583b969316a23c68d966dd1f43553053140f930b461d362d6-B65A39%7BCDY\(D\(\(W~DS5K$1A.png)

```
class Solution {
    List<List<Integer>> ret = new ArrayList<>();
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);  //先排序
        help(0, new ArrayList<Integer>(), target, candidates, 0);
        return ret;
    }
    public void help(int i, List<Integer> oneSolve, int target, int[] candidates, int sum){
        if (sum == target){
            ret.add(new ArrayList<>(oneSolve));
            return;   //exit_1
        }

        for (; i < candidates.length; ) {
            if (sum + candidates[i] <= target){
                oneSolve.add(candidates[i]);
                help(i+1, oneSolve, target, candidates, sum+candidates[i]);
                //跳过重复的元素
                while ((i+1) < candidates.length && candidates[i] == candidates[i+1])
                    i++;
                
                //这个 i++ 是为了能从下一个元素继续递归，每次成功返回（exit_1）或者					   
                //失败（exit_2）后都会加1，以便从后一个元素继续开始
                i++;
                oneSolve.remove(oneSolve.size()-1);
            } else{
                break;   //exit_2
            }
        }
    }
}
```


