使用两个`Map`分别存储每个数字出现的次数和每个次数对应的数字个数。遍历数组`arr`得到第一个`Map`，遍历第一个`Map`得到第二个`Map`。第二个`Map`用`TreeMap`并将键值降序排列。遍历第二个`Map`，首先考虑出现次数最多的数字，删除出现次数最多的数字即可使数组大小减小最多。一旦数组大小减小到一半或更少，则返回删除的数字数量。
```
class Solution {
    public int minSetSize(int[] arr) {
        Map<Integer, Integer> numberCountMap = new HashMap<Integer, Integer>();
        for (int num : arr) {
            int count = numberCountMap.getOrDefault(num, 0);
            count++;
            numberCountMap.put(num, count);
        }
        Map<Integer, Integer> countNumbersMap = new TreeMap<Integer, Integer>(new Comparator<Integer>() {
            public int compare(Integer key1, Integer key2) {
                return key2 - key1;
            }
        });
        Set<Integer> numberSet = numberCountMap.keySet();
        for (int num : numberSet) {
            int count = numberCountMap.getOrDefault(num, 0);
            int nums = countNumbersMap.getOrDefault(count, 0);
            nums++;
            countNumbersMap.put(count, nums);
        }
        int halfLength = arr.length / 2;
        Iterator<Integer> iterator = countNumbersMap.keySet().iterator();
        int size = 0;
        int removeCount = 0;
        while (iterator.hasNext() && removeCount < halfLength) {
            int count = iterator.next();
            int nums = countNumbersMap.getOrDefault(count, 0);
            for (int i = 0; i < nums; i++) {
                removeCount += count;
                size++;
                if (removeCount >= halfLength)
                    return size;
            }
        }
        return size;
    }
}
```
