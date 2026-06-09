/**
 * Project:
 * Author : zhaozhen
 * Email  : 2399144252@qq.com
 * Date   : 2019/11/7
 *
 * 解题思路: 回溯算法解决问题 剪枝1:判断重复去重复 剪枝2:找到目标,后面的不会存在最优解
 *
 * 附上回溯算法基础模板
 *
 */
```
public class leetcode039 {

    List<List<Integer>> res = new ArrayList<List<Integer>>();
    public void backtrack(int[] nums , Stack<Integer> temp ,int sum ,  int target){

        for(int i = 0;i < nums.length;i++){

            //剪枝1:去重 3 5 和 5 3 只能选一个(3 5) 其余回溯
            if(temp.size()!= 0 && nums[i] < temp.peek()){
                continue;
            }

            temp.push(nums[i]);
            sum += nums[i];

            //剪枝2 找到目标 回溯
            if(sum == target){
                res.add(new ArrayList<>(temp));
            }else if(sum < target){
                backtrack(nums, temp,sum,target);
            }

            temp.pop();
            sum -= nums[i];
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        //排序 便于后面剪枝
        Arrays.sort(candidates);
        backtrack(candidates,new Stack<Integer>(),0,target);
        return res;
    }

    public static void main(String[] args) {
        leetcode039 leetcode039 = new leetcode039();
        leetcode039.combinationSum(new int[]{2,3,5},8);
    }


    //回溯算法基础模板
    public void backtrack(int[] nums , Stack<Integer> temp){

        for(int i = 0;i < nums.length;i++){

            if(**出口**){
                //TODO OUTPUT
            }

            //加入节点
            temp.push(nums[i]);
            //递归深入
            backtrack(nums, temp);
            //回溯
            temp.pop();
        }
    }

}
```