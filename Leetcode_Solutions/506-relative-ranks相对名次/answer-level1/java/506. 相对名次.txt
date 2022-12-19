/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/20
 *
 *
 *  解题思路: 复制当前的数据进行排序 然后遍历nums 对当前的nums[i]进行二分查找,获取它的排行，以此来确定他的排名 java中使用的是升序排列,因此第一位是最小的,最后一位是最大的
 *
 *  注意: java 想要降序排列 使用
 *Arrays.sort(nums_c, new Comparator<Integer>() {
 *  @Override
 *  public int compare(Integer o1, Integer o2) {
 *    return o2 - o1;
 *  }
 *});
 *  nums_c 必须是 Integer 类型
 *
 */
```
public String[] findRelativeRanks(int[] nums) {
    int[] nums_c = nums.clone();
    Arrays.sort(nums_c);

    String[] res = new String[nums.length];
    for(int i = 0;i < nums.length;i++){
        int l = Arrays.binarySearch(nums_c,nums[i]);
        if(l == nums_c.length - 1){
            res[i] = "Gold Medal";
        }else if(l == nums_c.length - 2){
            res[i] = "Silver Medal";
        }else if(l == nums_c.length - 3){
            res[i] = "Bronze Medal";
        }else{
            res[i] = String.valueOf(nums_c.length - l);
        }
    }
    return res;
}
```