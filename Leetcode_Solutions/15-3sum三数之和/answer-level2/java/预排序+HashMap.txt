首先利用二数之和的思想，将找三个数和为0变为找两个数和为目标数的负数。
然后利用map(这里也能考虑set的)排除用过的（这种情况下，会存在-1 0 1 -1的情况，在第一轮找了-1 0 1之后还会再翻出来）
进一步去除重复：预排序，使用快排
效率O(n²)
```
public  List<List<Integer>> twoSum(int []nums,int key, int start){
        List<List<Integer>> answer= new ArrayList<>();
        HashMap<Integer,Boolean> isUsed=new HashMap<>(20);
        HashMap<Integer,Integer> two=new HashMap<>(20);
        for(int i=start;i<nums.length;i++){
            if(isUsed.containsKey(nums[i])){
                continue;
            }
            int amb=key-nums[i];
            if(two.containsKey(amb)){
                isUsed.put(nums[i],true);
                isUsed.put(amb,true);
                List<Integer> list=new ArrayList<>();
                list.add(-1*key);
                list.add(nums[i]);
                list.add(amb);
                answer.add(list);
            }
            two.put(nums[i],i);
        }
        return answer;
    }
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> answer= new ArrayList<>();
        Arrays.sort(nums);
        HashMap<Integer,Boolean> isUsed=new HashMap<>(20);
        for(int i=0;i<nums.length;i++){
            if(isUsed.containsKey(nums[i])){
                continue;
            }
            List<List<Integer>> list= twoSum(nums,-1*nums[i],i+1);
            if(list!=null){
                isUsed.put(nums[i],true);
                for(List<Integer> amb:list){
                    answer.add(amb);
                }
            }

        }
        return answer;
    }
```
