### 解题思路
JAVA+去重代码
### 代码

```java
class Solution {

    public void copy_sublist(LinkedList<Integer> tmp,List<List<Integer>> results) {
        LinkedList<Integer> tmp2 = new LinkedList<Integer>();
        for(Integer num:tmp) {
            tmp2.add(num);
        }
        results.add(tmp2);
    }

    public void findSubsets(int[] nums,int index,LinkedList<Integer> tmp,List<List<Integer>> results) {
        if(index > nums.length-1) {
            copy_sublist(tmp,results);
            return;
        }
        //不放入
        findSubsets(nums,index+1,tmp,results);
        //放入
        tmp.add(nums[index]);
        findSubsets(nums,index+1,tmp,results);
        // System.out.println(nums[index]);
        tmp.removeLast();
        
    }

    public List<List<Integer>> remove_dul(List<List<Integer>> results){
        List<List<Integer>> new_results = new LinkedList<List<Integer>>();
        Set<List<Integer>> sets = new HashSet();
        for(List<Integer> tmp:results) {
            sets.add(tmp);
        }

         for(List<Integer> tmp:sets) {
            new_results.add(tmp);
        }

        return new_results;

    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> results = new LinkedList<List<Integer>>();
        
        if(n == 0) {
            results.add(new ArrayList<>());//空集
            return results;
        }

        findSubsets(nums,0,new LinkedList<Integer>(),results);
        return remove_dul(results);

        // return results;


        

        


    }
}
```