### 解题思路
时间复杂度O(n^2)，空间复杂度O(n)
挺好玩的，将数组分成两半，一正一负，正的挑两个看之和的相反数在负的数组里面有没有，再在负的数组里挑两个进行相同的步骤，思路比较清晰简单。
### 代码

```java
import java.util.*;
class Solution {

       public List<List<Integer>> threeSum(int[] nums) {
        if (nums == null || nums.length <= 2) {
            return new LinkedList<>();
        }
        Set<List<Integer>> result = new HashSet<>();
        Set<Integer> positiveOrZero = new HashSet<>();
        Set<Integer> negative = new HashSet<>();
        int[] pl = new int[nums.length];
        int[] nl = new int[nums.length];
        int posNum = 0;
        int negNum = 0;
        int zeroNum = 0;

        for (int num : nums) {
            if (num >= 0) {
                positiveOrZero.add(num);
                pl[posNum++]=num;
                if (num==0){
                    zeroNum++;
                    if(zeroNum==3){
                        result.add(Arrays.asList(0,0,0));
                    }
                }
            }else{
                negative.add(num);
                nl[negNum++]=num;
            }
        }

        helper(result, positiveOrZero, nl, negNum);
        helper(result, negative, pl, posNum);

        return new ArrayList<>(result);
    }

    private void helper(Set<List<Integer>> result, Set<Integer> sets, int[] array, int num) {
        for (int i = 0; i<num; i++){
            for (int j = i+1; j<num; j++){
                int sumNeg = 0 - (array[i] + array[j]);
                if (sets.contains(sumNeg)){
                    if (result.contains(Arrays.asList(array[j], array[i], sumNeg))) continue;
                    result.add(Arrays.asList(array[i], array[j], sumNeg));
                }
            }
        }
    }
}

```