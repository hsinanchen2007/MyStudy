改进的回溯算法，关键点：
（1）最关键的语句是不满足特定条件的要进行过滤；
（2）回溯时要往下移一位，selectedIndex = start+1，保证每个数字只是用一次，使用的这一次是最顶层for循环那次。
```java
 if(start > 0 && sortedCandidates[start] == sortedCandidates[start - 1] && !usedIndexes[start - 1]) {
    continue;
  }
//条件1: start等于0时，0-1会报空指针，所以必须start>0时再判断才有意义
//条件2：相邻两个元素如果相等，优先计算前一个，如果前一个没用到，则后面的就不要计算了，直接进行下一个。
//条件3：前一个元素没有用过，直接不要进行探索了。
```


Java语言，耗时3ms
```java
class Solution {
   private List<List<Integer>> result;
    //递归尝试的元素集合
    private List<Integer> recursiveTrials;

    /**
     * 排序之后的候选数字
     */
    private int[] sortedCandidates;
    /**
     * 构造函数
     */
    Solution()  {
         result = new ArrayList<>();
         recursiveTrials = new ArrayList<>();
     }
    
     public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        if(target <= 0) {
            // 所有数字（包括 target）都是正整数，无效目标返回空数组
            return Collections.emptyList();
        }
         // 从小到达排序，以保证递归调用
        Arrays.sort(candidates);
        //提升到类成员变量，减少递归函数参数传递效率牺牲
        sortedCandidates = candidates.clone();
        int selectedIndex = 0;
        boolean[] usedIndexes = new boolean[sortedCandidates.length];
        Arrays.fill(usedIndexes,false);
        backtrackOptimalSearch(target,selectedIndex,usedIndexes);
        return result;
    }
    
    /**
     * 回溯最优搜索算法，试探法
     */
    private void backtrackOptimalSearch(int target, int selectedIndex, boolean[] usedIndexes) {
        if(target < 0) {
            //目标值小于0，及时终止探索
            return;
        }
        if(target == 0) {
            // 等于零代表一个有效匹配，添加到返回结果中
            result.add(new ArrayList<>(this.recursiveTrials));
        }
      //从第0个元素开始选取
      for(int start = selectedIndex; start < sortedCandidates.length; start++) {
        int trialItem = sortedCandidates[start];
        if(trialItem > target) {
            //当前元素比目标值大立刻停止探索
            return;
        }
        if(start > 0 && sortedCandidates[start] == sortedCandidates[start - 1] && !usedIndexes[start - 1]) {
            continue;
        }
        //有效探索值添加到递归中
        this.recursiveTrials.add(trialItem);
        usedIndexes[start] = true;

        backtrackOptimalSearch(target-trialItem,start+1,usedIndexes);
        //原则上每次新开始之前要把trials清空，用一个删除一个，比较难理解
        //探索式最优查找以后，当前元素就丢弃，重新进行下一个元素的最优判断
        this.recursiveTrials.remove(this.recursiveTrials.size() - 1);
        usedIndexes[start] = false;
      }    
        
    }
}
```
