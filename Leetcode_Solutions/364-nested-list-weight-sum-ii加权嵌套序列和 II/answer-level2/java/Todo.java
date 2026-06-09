
```
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
 /*
  *     我的思路是先求深度再递归遍历，可以考虑使用层次遍历，先求深度再遍历，但不用递归，使用queue.
  */

class Solution {
    public int depth(List<NestedInteger> nestedList){
        int dep=1;
        for(NestedInteger item :nestedList){
            if(!item.isInteger()){
                dep=Math.max(dep,depth(item.getList())+1);
            }
        }
        return dep;
    }
    public int depthSumInverseHelper(List<NestedInteger> nestedList,int depth){
        int res=0;
        for(NestedInteger item:nestedList){
            if(item.isInteger()){
                res+=item.getInteger()*depth;
            }else{
                res+=depthSumInverseHelper(item.getList(),depth-1);
            }
        }
        return res;
    }
    public int depthSumInverse(List<NestedInteger> nestedList) {
        int dep = depth(nestedList);
        System.out.println(dep);
        return depthSumInverseHelper(nestedList,dep);

    }
}