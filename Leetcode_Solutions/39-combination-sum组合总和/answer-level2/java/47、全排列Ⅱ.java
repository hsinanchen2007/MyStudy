1. 解题思路
对数组进行排序，以便跳过重复的数；
![新建 Microsoft Visio Drawing.jpg](https://pic.leetcode-cn.com/feca485cdd1a60b9fbc57b18249306ae4cfa3c3f8abf797d34766753cb8c5106-%E6%96%B0%E5%BB%BA%20Microsoft%20Visio%20Drawing.jpg)
剪枝：需要记录同级调用排列函数中前一个出现的数pre，当再次回到此级调用排列函数时，即将排列的数与pre进行比较，若相同，则跳过该数执行。
2. 
```
class Solution {
    private List<List<Integer>> res = new LinkedList<>();
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        LinkedList<Integer> track = new LinkedList<>();
        boolean[] used = new boolean[nums.length];
        backtrace(nums, used, track);
        return res;
    }
    public void backtrace(int[] nums, boolean[] used, LinkedList<Integer> track){
        if(track.size() == nums.length){
            res.add(new LinkedList(track));
            return;
        }
        //pre用于记录前一个节点的数据,同级的初始比较数
        int pre = nums[0] - 1;
        //每次都要遍历整个数组连接未排列的数，used记录之前已经排列过的数
        for(int i = 0; i < nums.length; i ++){
            if(!used[i] && nums[i] != pre){
                //向下连接
                track.add(nums[i]);
                used[i] = true;
                backtrace(nums, used, track);
                //同级移动
                track.removeLast();
                //状态重置
                used[i] = false;
                pre = nums[i];
            }
        }
    }
}
```
