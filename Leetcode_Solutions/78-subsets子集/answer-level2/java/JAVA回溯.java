![image.png](https://pic.leetcode-cn.com/f5fea2d821b494c3b1d9220c9ab8ed81698a4c2d47f40256ad28c4a9ad8fbbd4-image.png)

代码及注释如下：
```
class Solution {
    List<List<Integer>> result=new LinkedList<List<Integer>>();
    public final List<List<Integer>> subsets(int[] nums) {
        //空指针处理
        if(nums==null){
            return result;
        }
        int length=nums.length;
        //递归的收集结果
        subsets(nums,new Stack<Integer>(),0,length,0);
        //空集也是子集，放入空集
        result.add(new ArrayList<Integer>());
        return result;
    }

    private final void subsets(int[] nums,Stack<Integer> stack,int depth,int length,int j){
        //回归条件，该条件与将临时结果写入结果集的时机配合
        if(depth==length+1){
            return;
        }
        for(int i=j;i<length;i++){
            stack.push(nums[i]);
            //每次新增元素，都是一个新的子集，写入结果集
            List<Integer> l=new ArrayList<Integer>(stack);
            result.add(l);
            //为确保不出现重复组合，每次新增元素按从小到大的顺序新增，即从i+1开始选下一个元素
            subsets(nums,stack,depth+1,length,i+1);
            //尝试完一种可能，回溯继续for循环尝试下一种可能
            stack.pop();
        }
    }
}
```
