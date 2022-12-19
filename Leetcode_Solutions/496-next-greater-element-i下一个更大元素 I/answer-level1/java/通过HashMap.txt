```java
public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] result = new int[nums1.length];
        for (int i = 0; i < result.length; i++) {
            result[i] = -2;
        }
        HashMap<Integer,Integer> hashMap = new HashMap<>();
        for (int i = 0; i < nums2.length; i++) {
            hashMap.put(nums2[i],i);
        }
        for (int i = 0; i < nums1.length; i++) {
            int index = hashMap.get(nums1[i]);
            for (int j = index; j < nums2.length; j++) {
                if (nums2[j] > nums1[i]) {
                    result[i] = nums2[j];
                    break;
                }
            }
            if (result[i] == -2) {
                result[i] = -1;
            }
        }
        return result;
    }
```
执行用时 :3 ms, 在所有 java 提交中击败了98.35% 的用户
内存消耗 :37.4 MB, 在所有 java 提交中击败了66.54%的用户