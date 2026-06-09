### 解题思路
递归解法，回溯：
1. 对元素i (0<= i <=n-1), 如果 i<=target, 则暂时加入解序列
2. 递归寻找 target = target-i, 继续在i元素当前寻找 （必要条件：一是不重复，二对解的顺序无要求）
3. 当target为0时，当前解序列满足要求，加入解集合
4. target不为0时重复1和2直至满足3

时间复杂度,如果target很大并且candicates的元素都很小，最坏情况 O(n^n)
拓展：
1）如果candicates乱序但不重复，无影响
2）如果candicates乱序且可能重复（因为可重复选择，一般不会这么出），则要排序，每次target-i之后将pos调整到重复数字的最后一个元素的索引上
3）如果candacates不重复，且不能重复取值，pos调整到元素i的下一个

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        if (candidates.length >= 1) {
            isValid(res, new ArrayList<>(), candidates, 0, target);
        }
        return res;
    }

    public void isValid(List<List<Integer>> res, List<Integer> tmp, int[] candidates, int pos, int target) {
        if (target == 0) { // 刚好满足 target ，加入解集合
            res.add(tmp);
        } else { // 还有商量的余地
            for (int i=pos; i<candidates.length; i++) {  // 剩下的每个小于target的还可以尝试
                if (candidates[i] <= target) {      
                    List<Integer> tmp2 = new ArrayList<>(tmp);
                    tmp2.add(candidates[i]);
                    isValid(res, tmp2, candidates,i, target-candidates[i]);
                }
            }
        }
    }
    
    
}
```