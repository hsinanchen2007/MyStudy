```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        //奇数
        List<Integer> oddList = new ArrayList<>();
        //偶数
        List<Integer> evenList = new ArrayList<>();
        int len = 0;
        //拆分
        for (int i= 0; i < nums.length; ++i){
            if (i % 2 == 0){
                evenList.add(nums[i]);
                len = len + nums[i];
            }else {
                oddList.add(nums[i]);
            }
        }
        int[] res = new int[len];
        int index = 0;
        int resIndex = 0;
        //遍历偶数
        for (int a : evenList){
            for (int i = 0; i < a; ++i){
                res[resIndex++] = oddList.get(index);
            }
            index++;
        }
        return res;
    }
}
```