List<Integer> 转int[] 方法： list.stream().mapToInt(Integer::valueOf).toArray();

```
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] aa = new int[500];
        List<Integer> list = new ArrayList<>();
        for (int kk : nums) {
            aa[kk]++;
        }
        for (int kk: nums) {
            int count = 0;
            for (int i=0;i<kk;i++) {
                if (aa[i] != 0) {
                    count += aa[i];
                }
            }
            list.add(count);
        }
        return  list.stream().mapToInt(Integer::valueOf).toArray();
    }
}
```