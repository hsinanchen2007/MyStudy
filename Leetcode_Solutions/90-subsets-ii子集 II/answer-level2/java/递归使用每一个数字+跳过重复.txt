提交结果：
执行用时 :1 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :37.9 MB, 在所有 Java 提交中击败了65.60%的用户

思路：如果不包含重复元素的话，很明显，遍历每个数字，使用或者不使用这个数字，最后有2的n次方种结果。
现在有重复的数字，还使用这种方法的话，就会包含相同的子集，比如有三个2，我可以选择使用第一个和第三个，也可以使用第二个和第三个，这样得到的是相同的子集。
     我想了个法子-----前面的2没有使用的话后面的2禁止使用（也就是跳过），这样可以达到表面重复子集的效果：
     同样举个栗子：比如有五个2 ，2 2 2 2 2
     我们可以这样选 2 2 2 2 2
     也可以        2 2 2 2 _
     也可以        2 2 2 _ _
     也可以        2 2 _ _ _
     也可以        2 _ _ _ _
     但是不可以     _ 2 2 2 _ 这样子，因为我第一个2没有使用，会跳过后面所有的2，达到一个避免重复的作用。


代码：
```
 public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);//废话不多说，排个序
        List<List<Integer>> res =new ArrayList<>();//结果集
        List<Integer> last=new ArrayList<>();
        useNext(res,last,nums,0);//递归入口
        return res;
    }
    private void useNext(List<List<Integer>> res, List<Integer> last,int[] nums, int n) {
        if (n==nums.length)res.add(last);//出口
        else {
            //使用这个位置的数字，加到列表中并向后递归
            List<Integer> tmp=new ArrayList<>(last);
            tmp.add(nums[n]);
            useNext(res,tmp,nums,n+1);
            //未使用这个位置的数字时， 他后面所有的相同数字也不要用，不要问我为什么，我就觉得这样可以避免重复集合
            while (n+1<nums.length&&nums[n+1]==nums[n])//这个循环是跳过重复数字
                n++;
            useNext(res,last,nums,n+1);
        }
    }
```

