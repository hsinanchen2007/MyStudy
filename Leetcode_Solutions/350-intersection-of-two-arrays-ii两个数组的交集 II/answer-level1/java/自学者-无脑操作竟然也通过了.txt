### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        List<Integer> ans = new ArrayList<>();
        List<Integer> usedIndex = new ArrayList();
        for(int i = 0; i < nums1.length; i++) {
            for(int j = 0; j < nums2.length; j++) {
                if(nums1[i] == nums2[j]) {                    
                        if(!usedIndex.contains(j)){
                            ans.add(nums2[j]);
                            usedIndex.add(j);
                            break;
                        }
                                        
                }
            }
        }
        int [] result = new int[ans.size()];
        int index = 0;
        for(Integer item:ans) {
            result[index++] = item;
        }
        return result;
    }
}
```