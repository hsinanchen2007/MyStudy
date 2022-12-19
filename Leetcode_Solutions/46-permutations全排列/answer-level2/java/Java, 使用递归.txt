    /* 排列,使用递归，以{1， 2， 3}的全排列举例
       {1, 2 , 3}的全排列等于以下的合集：
       1、{1， 2}的全排列+3
       2、{1， 3}的全排列+2 （即交换2,3）
       3、{3,  2}的全排列+1 （即交换1,3）        
*/
    
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        if (nums.length == 0) {
            return list;
        }
        //数组长度等于1时结束递归
        if (nums.length == 1) {
            List<Integer> slist = new ArrayList<>();
            slist.add(nums[0]);
            list.add(slist);
            return list;
        } else {
            List<List<Integer>> resultlist = new ArrayList<>();
            for (int i = nums.length - 1; i >= 0; i--) {
                // 交换最后一位与i
                if (i != nums.length - 1) {
                    int temp = nums[i];
                    nums[i] = nums[nums.length -1];
                    nums[nums.length -1] = temp;
                }
                int[] subnums = new int[nums.length - 1];
                System.arraycopy(nums, 0, subnums, 0, nums.length - 1);
                // 递归调用
                List<List<Integer>> templist = permute(subnums);
                for (int j = 0; j < templist.size(); j++) {
                    templist.get(j).add(nums[nums.length - 1]);
                    resultlist.add(templist.get(j));
                }
                // 交换回去，以备下一次交换
                int temp = nums[i];
                nums[i] = nums[nums.length -1];
                nums[nums.length -1] = temp;
            }
            return resultlist;
        }
    }