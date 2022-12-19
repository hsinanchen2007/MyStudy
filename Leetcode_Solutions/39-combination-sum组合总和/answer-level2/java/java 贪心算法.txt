### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> combinationResult = new ArrayList<>();
    List<Integer> combinationList = new ArrayList<>();

    public  List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        combination(candidates, candidates.length - 1, target);
        HashSet set = new HashSet(combinationResult);
        combinationResult.clear();
        combinationResult.addAll(set);
        return combinationResult;
    }

    public  void combination(int[] candidates, int index, int target) {
       //
        if (target == 0) {
            combinationResult.add(new ArrayList<>(combinationList));
            return;
        } else if (target < 0 || index < 0) {
            return;
        } else {
            int max = target / candidates[index];
            //先压入最大值
            for (int i = 0; i < max; i++) {
                    combinationList.add(candidates[index]);
            }
            for (int j = max; j >= 0; j--) {
                combination(candidates, index - 1, target - candidates[index] * j);

                if (j > 0)
                {
                    combinationList.remove(combinationList.size()-1);
                }

            }

        }


    }

}
```