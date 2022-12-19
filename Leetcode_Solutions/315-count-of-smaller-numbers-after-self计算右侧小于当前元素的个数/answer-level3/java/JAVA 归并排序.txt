```
class Solution {
    private int[] temp;
    private int[] counter;
    private int[] indexes;

    public List<Integer> countSmaller(int[] nums) {
        if (nums.length == 0) {
            return new ArrayList<>();
        }
        temp = new int[nums.length];
        counter = new int[nums.length];
        indexes = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            indexes[i] = i;
        }
        sort(nums, 0, nums.length - 1);
        return Arrays.stream(counter).boxed().collect(Collectors.toList());
    }

    public void sort(int[] array, int l, int r) {
        if (l == r) {
            return;
        }
        int mid = l + (r - l) / 2;
        sort(array, l, mid);
        sort(array, mid + 1, r);
        merge(array, l, mid, r);
    }

    private void merge(int[] array, int l, int mid, int r) {
        if (r + 1 - l >= 0) System.arraycopy(indexes, l, temp, l, r + 1 - l);
        for (int index = l, i = l, j = mid + 1; index <= r; index++) {
            if (i > mid) {
                indexes[index] = temp[j++];
            } else if (j > r) {
                indexes[index] = temp[i++];
                counter[indexes[index]] += r - mid;
            } else if (array[temp[i]] <= array[temp[j]]) {
                indexes[index] = temp[i++];
                counter[indexes[index]] += j - mid - 1;
            } else {
                indexes[index] = temp[j++];
            }
        }
    }
}
```
