回溯法的思想是 构建一棵解空间树
本题是 排列树
```
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        /*回溯法*/
        //定义集合存放最终结果
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        //从0开始进行回溯法
        backTrack(0, list, nums);
        return list;
    }
    
    //对数组进行 回溯法递归
    public void backTrack(int t, List<List<Integer>> list, int[] x){
        //第一种情况，当到达 解空间树 的 叶子结点 时，将结果输出
        if(t == x.length){
            List<Integer> arr = new ArrayList<>();
            for(int i = 0; i < x.length; i++){
                arr.add(x[i]);
            }
            list.add(arr);
        //第二种情况，未到达叶子结点
        }else{
            for(int i = t; i < x.length; i++){
                //将x[t] 和其之后的元素依次进行交换
                swap(x, i, t);
                //递归对下一层进行回溯
                backTrack(t + 1, list, x);
                //交换后的元素再换回来保持原始状态
                swap(x, i, t);
            }
        }
    }
    
    //定义交换函数
    public void swap(int[] x, int m, int n){
        int temp = x[m];
        x[m] = x[n];
        x[n] = temp;
    } 
}
```
