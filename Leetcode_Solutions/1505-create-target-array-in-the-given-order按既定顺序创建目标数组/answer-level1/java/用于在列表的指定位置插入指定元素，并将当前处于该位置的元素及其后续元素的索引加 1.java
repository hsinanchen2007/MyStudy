```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        List<Integer> list = new ArrayList<>();

        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (i>=index.length) {
                break;
            }
            list.add(index[i],nums[i]);
        }
        for (int j=0;j<list.size();j++) {
            res[j]=list.get(j);
        }
        return res;

    }
}
```
