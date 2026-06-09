回溯、递归，backTrace用回溯算法遍历第I位的所有可能
class Solution {
    private int sub = 0;
    List<List<Integer>> allArrayList;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        ArrayList<Integer> actArrayList = new ArrayList<>();
        allArrayList = new ArrayList<>();
        backTrace(candidates,target,0,actArrayList);
        return allArrayList;
    }
    private void backTrace(int [] candidates, int target, int i, ArrayList<Integer> actArrayList){
        if (sub == target ) {
            allArrayList.add(new ArrayList<>(actArrayList));
            return;
        } 
        for (int j = i; j < candidates.length; j++) {
            if (sub + candidates[j] <= target) {
                actArrayList.add(candidates[j]);
                sub = sub +candidates[j];
                backTrace(candidates,target,j,actArrayList);
                actArrayList.remove(actArrayList.size()-1);
                sub = sub - candidates[j];
            } 
        }
    }
}