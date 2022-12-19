```
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(candidates);    //将元素排序，便于取<traget元素剪枝；

        solve(candidates, target, res, temp, 0);
        return res;
    }

    public void solve(int[] candidates, int target, List<List<Integer>> res, List<Integer> temp, int pre){
        if(target==0){
            //临时变量防止覆盖;
            List<Integer> t = new ArrayList<>(temp);
            res.add(t);     //将组合放入解集；
            return;
        }

        for(int i=0;i<candidates.length;i++){
            //从头开始探索元素和是否能构成target,数组元素<=target剪枝;
            //设置pre,让下一次取元素须>=上次取得元素值，防止产生重复集合;
            if(candidates[i]<=target&&candidates[i]>=pre){
                temp.add(candidates[i]);
                pre = candidates[i];
                solve(candidates, target-candidates[i], res, temp, pre);
                temp.remove(temp.size()-1);         //回溯去除上次不符元素；
            }
        }
    }
}
```
