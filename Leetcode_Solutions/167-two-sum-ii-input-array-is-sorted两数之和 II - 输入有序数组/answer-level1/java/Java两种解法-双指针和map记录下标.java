1.利用map来记录下标
```
    public int[] twoSum(int[] numbers, int target) {
          Map<Integer, Integer> map = new HashMap();
        for (int i = 0; i < numbers.length; i++) {
            int num = target - numbers[i];
            if (map.containsKey(num)) {
                    return new int[]{map.get(num)+1, i+1};
            }
            map.put(numbers[i],i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }
```
2.使用双指针
```
    public static int[] twoSum2(int[] numbers, int target) {
        int low = 0, high = numbers.length - 1;
        while (low < high) {
            if (numbers[low] + numbers[high] == target) {
                return new int[]{low + 1, high + 1};
            }
            if (target - numbers[low] > numbers[high]) {
                low++;
            } else {
                high--;
            }
        }
        throw new IllegalArgumentException("no solution");
    }
```
