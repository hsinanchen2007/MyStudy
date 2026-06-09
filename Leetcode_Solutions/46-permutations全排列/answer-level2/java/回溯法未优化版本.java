```
    public static void main(String[] args) {
        int[] nums = {1,2,3};
        System.out.println(new Quanpailie40().permute(nums));
    }

/*    输入: [1,2,3]
    输出:
            [
            [1,2,3],
            [1,3,2],
            [2,1,3],
            [2,3,1],
            [3,1,2],
            [3,2,1]
            ]
            */
private List<List<Integer>> res = new ArrayList<>();
    private Map<Integer,Boolean> flag = new HashMap<>();
    public List<List<Integer>> permute(int[] nums) {
        if(nums == null){
            return null;
        }

        int len = nums.length;
        for(int i = 0;i<len;i++){
            flag.put(nums[i],false);
        }
        List<Integer> tmp = new ArrayList<>();
        helper(nums,len,tmp);
        return res;
    }

    private void helper(int[] nums,int len,List<Integer> tmp){
        if(tmp.size()==len){
            res.add(new ArrayList<>(tmp));
            return;
        }

        for(int i=0;i<len;i++){
            if(!flag.get(nums[i])){
                tmp.add(nums[i]);
                flag.put(nums[i],true);
                helper(nums,len,tmp);
                tmp.remove(tmp.indexOf(nums[i]));
                flag.put(nums[i],false);
            }
        }
        return;
    }
```
