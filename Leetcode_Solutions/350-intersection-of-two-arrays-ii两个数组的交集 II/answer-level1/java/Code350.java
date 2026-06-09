### 解题思路
用Map来记录nums1中的元素和出现次数，
然后nums2中进行匹配，有相同就加入list并计数减1

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int length1 = nums1.length;
        int length2 = nums2.length;
        if (length1 == 0 || length2 == 0) {
            return new int[]{};
        }

        if (length1 <= length2) {
            return realIntersect(nums1, nums2);
        }
        else {
            return realIntersect(nums2, nums1);
        }
    }

    private int[] realIntersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new TreeMap<>();
        for (int num: nums1) {
            if (map.containsKey(num)) {
                map.put(num, map.get(num) + 1);
            }
            else {
                map.put(num, 1);
            }
        }

        ArrayList<Integer> list = new ArrayList<>();
        for (int num: nums2) {
            Integer count = map.get(num);
            if (count != null && count > 0) {
                list.add(num);
                count = count - 1;
                if (count > 0) {
                    map.put(num, count);
                }
                else {
                    map.remove(num);
                }

                if (map.size() == 0) {
                    break;
                }
            }
        }

        int[] result = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            result[i] = list.get(i);
        }
        return result;
    }
}
```