```
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] res = new int[nums1.length];
        for(int i = 0; i < nums1.length; i++) {
            int index = 0;
            int value = nums1[i];

            // 找到value在nums2中的下标
            while(value != nums2[index]) {
                index++;
            }

            // nums2中是否有值大于value，从其右侧遍历
            while(index < nums2.length) {
                if(nums2[index] > value) {
                    // 若右侧有值大于value，则存储并退出循环
                    res[i] = nums2[index];
                    break;
                }
                index++;
            }

            // 判断j值确定是否为-1
            if(index == nums2.length) {
                // 若是到终点退出循环的，则表明不存在比value大的值
                res[i] = -1;
            }
        }
        return res;
    }
}
```
