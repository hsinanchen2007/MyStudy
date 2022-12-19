解题思路-详见代码注释：
```
class Solution {

  /**
   * <p>数组的每一位数字状态：选择（1） or 不选（0），因此，每一个子集可由一组二进制数表示；
   * <p>以 [1,2,3] 为例：000 表示 []，100 表示 [1]，101 表示 [1,3]；
   * <p>列举所有可能的二进制数组合，即得到所有可能的子集情况：
   * <p>二进制：000  001  010  011  100  101  110  111
   * <p>十进制：  0    1    2    3    4    5    6    7
   */
  public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> resultList = new LinkedList<>();
    if (nums == null) {
      return resultList;
    }
    /*
     * 子集数量：2 的 n 次幂（n = nums.length）
     * 且为组合情况对应十进制数的最大边界值
     */
    int total = 1 << nums.length;
    for (int count = 0; count < total; count++) {
      List<Integer> subList = new LinkedList<>();
      for (int index = 0; index < nums.length; index++) {
        // 获取每一位二进制数（选择状态）
        int status = (count >> index) & 1;
        if (status == 1) {
          subList.add(nums[index]);
        }
      }
      resultList.add(subList);
    }
    return resultList;
  }
}
```
