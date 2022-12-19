```java []
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        
        List<List<Integer>> result = new ArrayList<>();
        if (candidates == null){
            return result;
        }
        
        if (candidates.length == 0){
            //return result.add(new ArrayList<Integer>());  
            //直接return是错误的，因为add方法返回是bool类型
            result.add(new ArrayList<Integer>());
            return result;
        }
        
        Arrays.sort(candidates);
        ArrayList<Integer> sub = new ArrayList<>();
        findsub(candidates, target, result, sub, 0);
        return result;
    }
        
    private void findsub(int[] candidates, 
                        int target, 
                        List<List<Integer>> result, 
                        ArrayList<Integer> sub,
                        int i){
        if (target < 0){
            return;
        }
        if (target == 0){
            result.add(new ArrayList<Integer>(sub));
        }
        
        for (int start = i; start < candidates.length; start++){

            /*当给的数组里面有重复元素，需要写下面的。不写会造成重复计算
            if (start != 0 && candidates[start] == candidates[start - 1]) {
                continue;
            }
            不去重的时候，例[2,2,3,6] 6 时
            输出
            [[2,2,2],[2,2,2],[2,2,2],[2,2,2],[3,3],[6]]
            期望答案
            [[2,2,2],[3,3],[6]]*/
            sub.add(candidates[start]);
            findsub(candidates, target-candidates[start], result, sub, start);
            sub.remove(sub.size() - 1);
        }  
    }
}