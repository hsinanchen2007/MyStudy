### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int [] res = new int[nums1.length];
        for (int i = 0; i < nums1.length; i ++){
            for (int j = 0; j < nums2.length; j++){
                int flag = 0;
                if (nums1[i] == nums2[j]){
                    for (int z = j + 1; z < nums2.length; z++){
                        if (nums2[z] > nums1[i]){
                            res[i] = nums2[z];
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0){
                        res[i] = -1;
                    }
                    break;
                }
            }
        }
        return res;
    }
}
```