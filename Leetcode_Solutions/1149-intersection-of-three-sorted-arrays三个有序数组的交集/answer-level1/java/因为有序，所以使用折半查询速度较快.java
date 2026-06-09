
```
public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
       List<Integer> list = new ArrayList<>();
        for (int i : arr1) {
            if (Arrays.binarySearch(arr2, i) >= 0 && Arrays.binarySearch(arr3, i) >= 0) {
                list.add(i);
            }
        }

        return list;
    }
```
