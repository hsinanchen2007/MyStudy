### 解题思路
![IMG_FB5D327B9C38-1.jpeg](https://pic.leetcode-cn.com/030515a999a4e74fe76147233f1cd224326561b1c2c415baa6ab3068de0b08df-IMG_FB5D327B9C38-1.jpeg)


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

    public List<List<Integer>> subsets(int[] nums) {

        int n = nums.length;
        List<List<Integer>> results = new LinkedList<List<Integer>>();
        
        if(n == 0) {
            results.add(new ArrayList<>());//空集
            return results;
        }

        findSubsets(nums,0,new LinkedList<Integer>(),results);

        return results;


        

        


    }
}
```