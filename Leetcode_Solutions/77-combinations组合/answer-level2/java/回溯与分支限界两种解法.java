回溯耗时36ms，内存39MB<br />
分支限界耗时6ms，内存49.4MB
```
/**
 * Problem
 *     77.Combinations
 *     https://leetcode.com/problems/combinations/
 * Grade of difficulty
 *     Medium
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution{

    private List<List<Integer>> res;

    public List<List<Integer>> combine(int n, int k) {
        if(n==0||k==0){
            return Collections.emptyList();
        }
        res=new ArrayList<>();
        List<Integer> list=new ArrayList<>();
        combineByBranch(1,n,k,list);
        return res;
    }

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n^2)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 this solution is base on branch and bound
     *     2.2 circulate 1 to n-(k-list.size())+1 and backtracking i+1 at the same time
     *     2.3 if k=list.size(),end recursion,and put current list to result list
     * 3.About submit record
     *     3.1 6ms and 49.4MB memory in LeetCode China
     *     3.2 2ms and 39.3MB memory in LeetCode
     * 4.Q&A
     *     4.1 Q:Why is the time complexity of the two algorithms so different?
     *         A:I think it is about circulation times,this solution is wipe some useless recursion
     * @param current
     * @param n
     * @param k
     * @param list
     */
    private void combineByBranch(int current,int n,int k,List<Integer> list){
        if(k==list.size()){
            res.add(new ArrayList<>(list));
        }
        else{
            for(int i=current;i<=n-(k-list.size())+1;i++){
                list.add(i);
                combineByBranch(i+1,n,k,list);
                list.remove(list.size()-1);
            }
        }
    }

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n^2)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 this solution is base on backTracking
     *     2.2 circulate 1 to n and backtracking i+1 and k-1 at the same time
     *     2.3 if k=0,end recursion,and put current list to result list
     * 3.About submit record
     *     3.1 36ms and 39MB memory in LeetCode China
     *     3.2 19ms and 41.8MB memory in LeetCode
     * 4.Q&A
     * @param current
     * @param n
     * @param k
     * @param list
     */
    private void combineByBackTracking(int current,int n,int k,List<Integer> list){
        if(k==0){
            res.add(new ArrayList<>(list));
        }
        else{
            for(int i=current;i<=n;i++){
                list.add(i);
                combineByBackTracking(i+1,n,k-1,list);
                list.remove(list.size()-1);
            }
        }
    }
}
```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路