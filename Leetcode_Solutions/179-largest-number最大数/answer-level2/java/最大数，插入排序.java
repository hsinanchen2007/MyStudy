算法思路：插入排序，排序时的比较依据为 a+b和b+a的desc顺序
代码：
```
    public String largestNumber(int[] nums) {
        List<Integer> result = new LinkedList<>();
        result.add(nums[0]);
        int sortedIndex = 0, unsortedIndex = sortedIndex + 1;
        while (unsortedIndex < nums.length) {
            int comming = nums[unsortedIndex];
            for (int i = 0; i < unsortedIndex; i++) {
                int current = result.get(i);
                if ((current + String.valueOf(comming)).compareTo(String.valueOf(comming) + current) < 0) {
                    result.add(i, comming);
                    break;
                } else {
                    if (i == unsortedIndex - 1) {
                        result.add(i + 1, comming);
                    }
                }
            }
            unsortedIndex++;
        }
        StringBuilder ret = new StringBuilder();
        for (Integer i : result) {
            if (i == 0 && ret.length() == 0) {
                continue;
            }
            ret.append(i);
        }
        if (ret.length() == 0) {
            ret.append(0);
        }
        return ret.toString();
    }
```
