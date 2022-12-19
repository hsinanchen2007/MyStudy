### 解题思路
思路其实比较简单, 就是把数组哈希化为 numSet, 对 numSet 进行遍历, 检查每一个数字的临近数字是否存在于数组中, 若存在则继续向left, right两侧延伸, 而此连续序列的长度就是 right-left.

已经访问过的数字都保存在另一个哈希数组 visitedSet 中, 优化包括如果数字已经被访问过则 continue, 同时若 numSet 中剩余的已经小于 max, 那么必然不会再产生更长的序列, 所以可以直接结束.


### 代码

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> numSet=new HashSet<>();
        for(int n:nums) numSet.add(n);
        Set<Integer> visitedSet=new HashSet<>();
        int max=0;

        for(int n:numSet){
            if(visitedSet.contains(n)){
                continue;
            }
            int left=n-1;
            int right=n+1;
            visitedSet.add(n);

            while(!visitedSet.contains(left)&&numSet.contains(left)){
                visitedSet.add(left);
                left--;
            }
            while(!visitedSet.contains(right)&&numSet.contains(right)){
                visitedSet.add(right);
                right++;
            }
            max=Math.max(max,right-left-1);
            if(max>numSet.size()-visitedSet.size()) break;
        }
        return max;
    }
}
```