位图法：构造相同长度的数组 bitMap, bitMap[i] 表示数字 i+1是否存在（数组从 0 开始，数据从 1 开始）。先遍历一遍原数组，将所有数字填充到 bitMap 中，此时可以确定重复的那个数字。
然后再遍历一遍 bitMap，获取值为 0 的那个数组下标，即是缺少的那个数字。

时间复杂度 O(2n), 空间占用n 多一点。
```
class Solution {
    public int[] findErrorNums(int[] nums) {

        Boolean[] bitMap = new Boolean[nums.length];
        int[] result = new int[2];
        for (int num : nums ) {
            if (bitMap[num-1] == null) {
                bitMap[num-1] = true;
            }else {
                // 此数字已经存在过
                result[0] = num;
            }
        }
        for (int i=0;i<bitMap.length;i++) {
            if (bitMap[i] == null) {
                result[1] = i+1;
                break;
            }
        }
        return result;
    }
}
```
