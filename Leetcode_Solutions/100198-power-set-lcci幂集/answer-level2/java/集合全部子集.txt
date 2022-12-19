### 解题思路
集合的特点是相同元素构成同一个集合，这一点区别于排列，故递归时只需要一次某一个元素以后依次递归即可。
first标记每次递归开始的位置，first之前的元素表示已经用过了，只需要递归first后边的元素即可。
num标记每次递归，子集的元素总个数，一个含有n个元素的集合可以有n+1个不同的num.

### 代码

```java
//集合的所有子集，注意集合和全排列不同
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> tem = new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
        for(int i = 0;i<=nums.length;++i){
            tem.clear();
            helper(nums,i,0);
        }
        return res;
    }
    private void helper(int[] nums,int num,int first){
        if(tem.size() == num){
            res.add(new ArrayList(tem));
            return;
        }
        for(int i = first;i<nums.length;++i){
            tem.add(nums[i]);
            helper(nums,num,i+1);
            tem.remove(new Integer(nums[i]));
        }
    }
}
```