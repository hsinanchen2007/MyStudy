我采用的思路是将两数和作为新数组，再利用两数之和的最优解法字典映射。在计算两数和时可以同时完成从字典中取出匹配值，理论上最快效率为o(N^2)，但速度并不理想，速度仅击败56%，内存击败86%

看了下速度排名前面的双指针解法，想来跟双指针解法较容易事先筛除较多的数据有关，映射法目前我只能筛除很小的一部分数据提升效率

code 如下

```
int[] nums;
public List<List<Integer>> fourSum(int[] nums, int target) {
    this.nums = nums;
    Arrays.sort(nums); // o(NlogN)
    List<List<Integer>> list = new ArrayList<>();
    Set<DoubleSum> set = new HashSet<>(nums.length);
    Map<Integer, List<DoubleSum>> map = new HashMap<>(nums.length);
    int min = nums.length >= 2 ? nums[0] + nums[1] : 0;
    int max = nums.length >= 2 ? nums[nums.length - 2] + nums[nums.length - 1] : target;
    for (int i = 0; i < nums.length - 1; i++) {
        if (min + nums[i] + nums[i + 1] > target
                || max + nums[i] + nums[nums.length - 1] < target) continue;
        for (int j = i + 1; j < nums.length; j++) {
            // o(N2)

            if (min + nums[i] + nums[j] > target
                    || max + nums[i] + nums[j] < target) continue;

            DoubleSum ds = new DoubleSum(i, j);
            if (set.contains(ds)) { // 理论最佳o(1)
                continue;
            }

            int intent = target - ds.sum;
            List<DoubleSum> matchList = map.get(intent); // 理论o(1)
            if (matchList != null) {
                for (DoubleSum ds2 : matchList) { // 这里有部分性能消耗
                    List<Integer> resultItem = ds2.associate(ds);
                    if (resultItem != null) list.add(resultItem);
                }
            }

            List<DoubleSum> addList = map.get(ds.sum); // 理论o(1)
            if (addList == null) {
                addList = new ArrayList();
                map.put(ds.sum, addList);
            }
            addList.add(ds);
        }
    }
    list = list.stream().distinct().collect(Collectors.toList()); // 这里也有部分性能消耗

    return list;
}

public class DoubleSum implements Comparable<DoubleSum> {
    int index1;
    int index2;

    int sum;

    public DoubleSum(int index1, int index2) {
        if (index1 > index2) {
            this.index1 = index2;
            this.index2 = index1;
        } else {
            this.index1 = index1;
            this.index2 = index2;
        }
        this.sum = nums[this.index1] + nums[this.index2];
    }

    public boolean equals(Object obj) {
        //if (!(obj instanceof DoubleSum)) {
        //    return false;
        //}
        DoubleSum ds = (DoubleSum)obj;
        return this.index1 == ds.index1 && this.index2 == ds.index2;
    }

    public int hashCode() {
        return (this.index1 << 16) + (this.index1 >> 16) + (this.index2 << 16) + (this.index2 >> 16);
    }

    public int compareTo(DoubleSum ds) {
        return this.sum - ds.sum;
    }
    public List<Integer> associate(DoubleSum ds) {
        if (this.index1 == ds.index1 || this.index1 == ds.index2
                || this.index2 == ds.index1 || this.index2 == ds.index2) {
            return null;
        }
        List<Integer> list = new ArrayList<>();
        list.add(nums[this.index1]);
        list.add(nums[this.index2]);
        list.add(nums[ds.index1]);
        list.add(nums[ds.index2]);
        // 为了方便后面的distinct
        list = list.stream().sorted().collect(Collectors.toList()); // 这里也有部分性能消耗
        return list;
    }
}
```
