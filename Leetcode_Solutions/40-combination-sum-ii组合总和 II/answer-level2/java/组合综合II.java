一、
### 解题思路
思路还是深度优先遍历+剪枝
注意有一下两点：
1、本题相较39题仅仅要多加一个条件而已，因为本题每个数字只能使用一次，于是多加一个变量用来表示是否使用过List<Integer>used, 用于保存使用过的下标，当使用这个数组元素时，将其下标保存到used(把list当栈使用，嘻嘻！))的栈顶中，递归调用完之后，将栈顶元素弹出就行啦。
2、最后还需要进行去重，下面代码用的是set进行去重。

todo: 本代码结果很慢，嘿嘿！需要改进!😋
### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Set<List<Integer>> result = new HashSet<>();
        Arrays.sort(candidates);
        List<Integer> used = new ArrayList<>();
        getResult(candidates, 0, used, target , result, 0, new ArrayList<>());
        return new ArrayList<>(result);
    }

    public void getResult(int[] candidates, int start, List<Integer> used, int target, Set<List<Integer>> result, int curSum, List<Integer> oneResult) {
        if (curSum > target) {
            return;
        }
        if (curSum == target) {
            result.add(new ArrayList<>(oneResult));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (used.contains(i)) {
                continue;
            }
            used.add(i);
            oneResult.add(candidates[i]);
            getResult(candidates, i, used, target, result, curSum+candidates[i], oneResult);
            oneResult.remove(oneResult.size()-1);
            used.remove(used.size()-1);
        }
    }
}
```
二、
### 解题思路
进行了改进，
不在使用List<Integer>used, 每次从他的下一个下标开始，绝对不会包含本身

结果：速度和内存还是不理想😋
### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Set<List<Integer>> result = new HashSet<>();
        Arrays.sort(candidates);
        getResult(candidates, 0, target , result, 0, new ArrayList<>());
        return new ArrayList<>(result);
    }

    public void getResult(int[] candidates, int start, int target, Set<List<Integer>> result, int curSum, List<Integer> oneResult) {
        if (curSum > target) {
            return;
        }
        if (curSum == target) {
            result.add(new ArrayList<>(oneResult));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            oneResult.add(candidates[i]);
            getResult(candidates, i+1, target, result, curSum+candidates[i], oneResult);
            oneResult.remove(oneResult.size()-1);
        }
    }
}
```
