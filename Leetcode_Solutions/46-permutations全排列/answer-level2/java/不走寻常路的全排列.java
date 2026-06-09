因为是不重复的，所以用了这个方法。结果：运行时间1ms。

全排列II用这个思路做了一些剪枝，但由于思路的局限性，效果不是很好，最后还是要去重。

思路：遍历添加元素到一个list中。list为空时，直接add();list不为空时，添加一个元素，有list.size()个位置可以选择，然后遍历都选一遍插进去，再利用递归和回溯，直到所有元素都放到list中，ok，一个排列结果出来了。
```
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> results = new ArrayList<List<Integer>>();
        List<Integer> result = new ArrayList<Integer>();
        getAllPermutation(results,result,nums,0);
        return results;
    }
                       
    public void getAllPermutation(List<List<Integer>> results,List<Integer> result,int[] nums,int index){
        if(index == nums.length){
            List<Integer> temp = new ArrayList<Integer>(result);
            //添加代码if(!results.contains(temp))去重
            results.add(temp);
        }
        else{
           for(int i = 0;i <= result.size();i++){
                if(i == result.size()){
                    result.add(nums[index]);
                }
                else{
                    result.add(i,nums[index]);
                }
                getAllPermutation(results,result,nums,index+1);
                result.remove(i);
                /*这里添加的代码时全排列II里的操作
                if(i == result.size()){
                   result.add(nums[index]);
                   getAllPermutation(results,result,nums,index+1);
                   result.remove(i);
                }
                else{
                    //这里可以去掉部分重复
                   if(nums[index] != result.get(i)){
                       result.add(i,nums[index]);
                       getAllPermutation(results,result,nums,index+1);
                       result.remove(i);
                   } 
               }*/
           }
        }   
    }
```
