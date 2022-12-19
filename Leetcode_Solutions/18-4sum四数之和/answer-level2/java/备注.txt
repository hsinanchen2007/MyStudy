### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Map<Integer, List<Pair<Integer, Integer>>> stores = new HashMap<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int num = nums[i] + nums[j];
                if (stores.containsKey(num)) {
                    stores.get(num).add(new Pair<>(i, j));
                } else {
                    List<Pair<Integer, Integer>> tmp = new ArrayList<>();
                    tmp.add(new Pair<>(i, j));
                    stores.put(num, tmp);
                }
            }
        }

        Set<List<Integer>> rets = new HashSet<>();
        for (int k = 0; k < nums.length; k++) {
            for (int l = k + 1; l < nums.length; l++) {
                int num = target - nums[k] - nums[l];
                if (!stores.containsKey(num)) {
                    continue;
                }

                for (Pair<Integer, Integer> pair : stores.get(num)) {
                    int i = pair.getKey();
                    int j = pair.getValue();
                    if ((i != k) && (i != l) && (j != k) && (j != l)) {
                        List<Integer> tmp = new ArrayList<>();
                        tmp.add(nums[i]);
                        tmp.add(nums[j]);
                        tmp.add(nums[k]);
                        tmp.add(nums[l]);
                        // 排序的目标是为了后面的去重
                        tmp.sort(Comparator.comparingInt(o -> o));
                        rets.add(tmp);
                    }
                }
            }
        }

        return new ArrayList<>(rets);
    }
}
```