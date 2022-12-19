参考了其他同学的作品，进行代码精简优化，便于理解回溯法。
回溯法是一种选优搜索法，按选优条件向前搜索，以达到目标。但当探索到某一步时，发现原先选择并不优或达不到目标，就退回一步重新选择，这种走不通就退回再走的技术为回溯法，而满足回溯条件的某个状态的点称为“回溯点”。许多复杂的，规模较大的问题都可以使用回溯法，有“通用解题方法”的美称。


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
    
     public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if(target <= 0) {
            // 所有数字（包括 target）都是正整数，无效目标返回空数组
            return result;
        }
         // 从小到达排序，以保证递归调用
        Arrays.sort(candidates);
        //提升到类成员变量，减少递归函数参数传递效率牺牲
        sortedCandidates = candidates.clone();
        int selectedIndex = 0;
        // 递归调用掺杂上函数返回值将变得比较难以理解，
        // 此处直接改为类变量，让代码更容易理解，效率会更高。
        backtrackOptimalSearch(target,selectedIndex);
        return result;
    }
    
    /**
     * 回溯最优搜索算法，试探法
     */
    private void backtrackOptimalSearch(int target, int selectedIndex) {
        if(target < 0) {
            //原选择达不到目标
            //目标值小于0，及时终止探索
            return;
        }
        if(target == 0) {
            // 原选择达到最优选，将选择的数据存储起来（一路差值计算后等于目标值了）
            // 等于零代表一个有效匹配，添加到返回结果中
            result.add(new ArrayList<>(this.recursiveTrials));
this.recursiveTrials
        }
      //从第0个元素开始选取，
      for(int start = selectedIndex; start < sortedCandidates.length; start++) {
          int trialItem = sortedCandidates[start];
          if(trialItem > target) {
              //当前元素比目标值大立刻停止探索
              break;
          }
          //有效探索值添加到递归中
          this.recursiveTrials.add(trialItem);
          
          backtrackOptimalSearch(target-trialItem,start);
          
          //此处是最难理解的删除：其实是选择一个元素，回溯最优搜索以后，要求确保前面判断的不要再重复判断以一次
          //探索式最优查找以后，当前元素就丢弃，重新进行下一个元素的最优判断
          this.recursiveTrials.remove(this.recursiveTrials.size() - 1);
      }    
        
    }
    
}
```
