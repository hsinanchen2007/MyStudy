
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/11/8
 * 
 * 解题思路: 回溯算法解决问题 剪枝1:判断重复去重复(同一个父节点的子节点必须是不同的值 方法:排序+hash判断) 剪枝2:找到目标,后面的不会存在最优解
 * 
 */
```
public class leetcode040 {

    List<List<Integer>> res = new ArrayList<>();
    public void backtrack(int[] nums , int start , int target , Stack<Integer> temp, int sum){

        HashSet hashSet = new HashSet();
        for(int i = start ; i < nums.length ; i ++){
            //剪枝1 同一个父节点的子节点必须是不同的值
            if(hashSet.contains(nums[i])){
                continue;
            }else{
                hashSet.add(nums[i]);
            }

            temp.push(nums[i]);
            sum += nums[i];

            //剪枝2 获取到目标,回溯
            if(sum == target){
                res.add(new ArrayList<>(temp));
//                这里可以再次剪枝 直接终止
//                temp.pop();
//                sum -= nums[i];
//                return;
            }else if(sum < target){
                backtrack(nums,i + 1 , target , temp , sum);
            }

            temp.pop();
            sum -= nums[i];
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        backtrack(candidates , 0 , target , new Stack<Integer>() , 0);
        return res;
    }

    public static void main(String[] args) {

    }

}

```