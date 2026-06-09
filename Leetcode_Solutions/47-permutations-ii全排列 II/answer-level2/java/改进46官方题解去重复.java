// 参考46官方题解，只需要添加一句判断当前结点是否在前面重复出现过便可以了(本来也看了第一个题解用栈的想法，但是花了半天从46官方题解的思路换到他的，最后想了想还是继续改官方的吧，感觉官方的好懂写😂)
// 具体为什么可以用[1,2,1,2]按官方题解思路走一遍就知道了，毕竟自己动手更容易理解(当初就是卡[1,1,2,2]卡了半天)
// ```
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> output = new LinkedList<>();
        ArrayList<Integer> nums_list = new ArrayList<>();
        for (int num:nums){
            nums_list.add(num);
        }
        int n = nums.length;
        backTrack(n, nums_list, output, 0);
        return output;
    }
    
    private void backTrack(int n, ArrayList<Integer> nums, List<List<Integer>> output, int first){
        if (first == n){
            output.add(new ArrayList<>(nums));
            return;
        }
        for (int i=first; i<n; i++){
            if (!isRepeat(nums, first, i)){
                Collections.swap(nums, first, i);
                backTrack(n, nums, output, first+1);
                Collections.swap(nums, first, i);
            }
        }
    }
    private boolean isRepeat(ArrayList<Integer> nums, int first, int n){
        int temp = nums.get(n);
        for (int i=first; i<n; i++){
            if (nums.get(i) == temp){
                return true;
            }
        }
        return false;
    }
// ```
// 回溯法题可以分为子集树和排列树，这个题是排列树，子集树可以看[51.N皇后](https://leetcode-cn.com/problems/n-queens/solution/biao-zhun-de-hui-su-fa-si-xiang-deng-jie-yu-sou-su/)我的题解