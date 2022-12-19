### 解题思路
1.采用普通回溯，发现时间耗费巨大
2.采用生成公式，直接输出

### 代码

```java
class Solution {
    private int maxLength;
    //private boolean isSuccess = false;

    public List<Integer> grayCode(int n) {
        // maxLength = (int) Math.pow(2D, n);
        // List<Integer> results = new ArrayList<>(maxLength);
        // int[] nums = new int[maxLength];
        // for (int i = 0; i < maxLength; i++) {
        //     nums[i] = i;
        // }
        // results.add(0);
        // backTracking(nums, results);
        // return results;
        maxLength = (int) Math.pow(2D, n);
        List<Integer> results = new ArrayList<>(maxLength);
        for (int i = 0; i < maxLength; i++){
            results.add(generateGrayCode(i));
        }
        return results;
    }

    /**
     * Generate gray code
     * G(n) = B(n) XOR B(n+1)
     * @param num binary code
     * @return    gray code
     */
    private int generateGrayCode(int num){
        return num ^ (num >> 1);
    }

    // private void backTracking(int[] nums, List<Integer> results) {
    //     if (results.size() == maxLength){
    //         isSuccess = true;
    //         return;
    //     }
    //     for (int i = 1; i < nums.length; i++){
    //         if (nums[i] == 0){
    //             continue;
    //         }
    //         if (!isValid(nums[i],results)){
    //             continue;
    //         }
    //         // 如果符合条件，即2个连续数值只能有一个位差异
    //         int saveNum = nums[i];
    //         nums[i] = 0;
    //         results.add(saveNum);
    //         backTracking(nums,results);
    //         if (isSuccess){
    //             return;
    //         }
    //         nums[i] = saveNum;
    //         results.remove(results.size() - 1);
    //     }
    // }

    // private boolean isValid(int seq, List<Integer> results) {
    //     return ((seq ^ results.get(results.size() - 1)) & ((seq ^ results.get(results.size() - 1)) - 1)) == 0;
    // }
}
```