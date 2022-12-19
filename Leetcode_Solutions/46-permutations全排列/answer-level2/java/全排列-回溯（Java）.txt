```java
class Solution {
    List<List<Integer>> lists = new ArrayList<>();
    boolean isUsed[]; //标记当前位置的元素是否被使用过，初始化为false
    boolean isFirst = true;  //是否为第一个排列
    List<Integer> list = new ArrayList<>(); //存储每一个排列

    public List<List<Integer>> permute(int[] nums) {
        isUsed = new boolean[nums.length];
        permute(nums, 0);
        return lists;
    }


    public void permute(int[] nums, int n){
        //当前排列的个数与数组长度相同，一次排列结束
        if(n == nums.length){
            isFirst = false;
            //需要new一个list。否则地址相同所有的结果都是最后一次排列
            lists.add(new ArrayList<>(list));
            return;
        }
        //遍历数组
        for (int i = 0; i < nums.length; i++) {
            //如果没有使用过这个数，则排列
            if(!isUsed[i]){
                isUsed[i] = true; //设置为已经使用过
                if(isFirst) list.add(nums[i]); //如果是第一次排列，则直接加入list
                if(!isFirst) list.set(n, nums[i]); //如果不是第一次排列，修改当前下标的值
                permute(nums, n + 1); //继续排列下一个数
                isUsed[i] = false; //回溯，改为未使用过
            }
        }
        return;
    }
}
```