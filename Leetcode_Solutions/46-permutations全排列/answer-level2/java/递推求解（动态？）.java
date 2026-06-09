[1,2,3]
思路比较简单，模拟人的思路
设解空间为f(n)
那么解为
1. 1为第一个数字+ f(n-1)
2. 1和后面的数字依次对调， 比如[2,1,3], 2为第一个数字+f(n-1)
其实就是n个f(n-1) 

  

List<List<Integer>>  result = new ArrayList<>();
    public List<List<Integer>> permute(int[] nums) {
        int[] buf = new int[nums.length];
        permuteItem(buf, nums, 0);
        return result;
    }
    public void permuteItem(int[] buf, int[]nums, int offset) {
        if (offset == nums.length -1) {
            buf[offset] = nums[offset];
            List<Integer> tmp = new ArrayList<>();
            for(int i:buf) {
                tmp.add(i);
            }
            result.add(tmp);
            return;
        }
        for(int i=offset; i<nums.length; i++) {
            swap(nums, offset, i);
            buf[offset]= nums[offset];
            permuteItem(buf, nums, offset+1);
            swap(nums,  i,offset);
        }
    }
    public void swap(int[] nums, int start, int end) {
        int tmp = nums[end];
        nums[end] = nums[start];
        nums[start] = tmp;
    }