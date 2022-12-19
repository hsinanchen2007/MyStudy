```
public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] result = new int[nums1.length];
        for (int i=0;i<nums1.length;i++) {
            boolean flag = false;
            result[i] = -1;
            for (int i2 : nums2) {
                if(nums1[i]==i2){
                    flag = true;
                }
                if(flag && i2>nums1[i]){
                    result[i] = i2;
                    break;
                }
            }
        }
        return result;
    }
}
```
实在是不知道怎么用栈去解决。
