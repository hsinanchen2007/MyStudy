

### 代码
```java
class Solution {
    public static int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> hmap = new HashMap<>();
        //存放nums1中对应元素在nums2中的位置
        for (int i = 0; i < nums2.length; i++) {
        	hmap.put(nums2[i], i);
        }
        for (int i = 0; i < nums1.length; i++) {
            int old = nums1[i];
            for (int j = hmap.get(old); j < nums2.length; j++) {
                if(nums2[j]>nums1[i]){
                    nums1[i] = nums2[j];
                    break;
                }
            }
            //如果该位没有发生变化,则视为没有找到,置为-1
            if(nums1[i] == old){
                nums1[i]=-1;
            }
        }
        return nums1;
    }
}