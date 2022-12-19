### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> result = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if(candidates.length == 0) return result;
        Arrays.sort(candidates);
        backtrack(candidates, 0, target, new LinkedList<Integer>());
        return result;
    }
    private void backtrack(int[] candidates, int depth, int target, LinkedList<Integer> list){
        if(target == 0){
            result.add(new ArrayList<>(list));
            return;
        }
        if(target < 0) return;
        // 先排序, i从depth开始而不是从0开始, 这样只可能找后面的元素, 不可能回头找前面的
        for(int i=depth; i<candidates.length; i++){
            int elem = candidates[i];
            list.addLast(elem);
            backtrack(candidates, i, target - elem, list);
            list.removeLast();
        }
    }
}
```