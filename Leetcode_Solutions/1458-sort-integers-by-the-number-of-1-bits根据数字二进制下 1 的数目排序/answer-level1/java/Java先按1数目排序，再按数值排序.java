```
class Solution {
    public int[] sortByBits(int[] arr) {
        List<Integer> list = Arrays.stream(arr).boxed().collect(Collectors.toList());
        Collections.sort(list, Comparator.comparing(this::getOneCount)
                .thenComparing(Comparator.naturalOrder()));
        return list.stream().mapToInt(i -> i).toArray();
    }

    int getOneCount(int num) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (((num >> i) & 1) == 1) {
                count++;
            }
        }
        return count;
    }
}
```
