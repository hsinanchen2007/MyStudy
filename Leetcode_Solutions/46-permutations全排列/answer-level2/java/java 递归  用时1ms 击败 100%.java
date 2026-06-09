![image.png](https://pic.leetcode-cn.com/8c3781796dbf521667933e87777d0a70fce8be162ba92160ed54d750e30fa877-image.png)

解题思路
    1.固定开始元素,剩下的元素进行全排列
    2.继续固定下一位元素,剩下的元素进行全排列
    3.递归终点为最后一个元素
    4.交换下一个元素,重复执行第一步,直到所有元素替换完成


```
    //保存所有结果的集合
    private List<List<Integer>> listNums = new ArrayList<>();
    public List<List<Integer>> permute(int[] nums) {
        p(0,nums);
        return listNums;
    }

    //全排列方法
    public void p(int start,int[] nums){
        //递归终止条件,已经是最后一个元素
        if (start >= nums.length - 1){
            //一组排列
            List<Integer> nnnn = new ArrayList<>();
            for (int i = 0; i < nums.length; i++) {
                nnnn.add(nums[i]);
            }
            listNums.add(nnnn);
            return;
        }
        //以第i个元素开头,剩下的元素排列
        for (int i = start; i <nums.length; i++) {
            //第i个元素和首元素交换
            swap(i,start,nums);
            //递归调用,以第i+1个元素开头,剩下的玄素进行全排列
            p(start+1,nums);
            //交换回来
            swap(i,start,nums);
        }
    }
    //交换元素方法
    public void swap(int source,int target,int nums[]){
        int temp = nums[target];
        nums[target] = nums[source];
        nums[source] = temp;
    }

```
