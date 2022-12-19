- 用数组记录nums中元素的索引，判断是否已添加当前索引下的元素

```
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums);
        int[] index = new int[nums.length];
        Arrays.fill(index,-1);
        help(nums,list,index,new ArrayList<Integer>());
        return list;
    }
    public void help(int[] nums,List<List<Integer>> list,int[] index,List<Integer> li){
        if(li.size()==nums.length) {
            list.add(new ArrayList<Integer>(li));
            return;
        }
        for(int i=0; i<nums.length; i++){
            if(index[i] == i) continue; //索引等于i,说明li已存入当前索引的元素
            index[i] = i;               //index记录li存入元素的索引
            li.add(nums[i]);
            help(nums,list,index,li);
            index[i] = -1;
            li.remove(li.size()-1);
            while (i<nums.length-1 && nums[i]==nums[i+1]) i++; //回溯剪枝
        }
    }
}
```
