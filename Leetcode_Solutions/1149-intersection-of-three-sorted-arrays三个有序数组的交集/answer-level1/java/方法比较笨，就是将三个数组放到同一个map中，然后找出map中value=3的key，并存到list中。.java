```
class Solution {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        Map<Integer, Integer> map = new HashMap<>();
        List arrayList = new ArrayList();
        putArray(arr1, map);
        putArray(arr2, map);
        putArray(arr3, map);

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue().equals(3)) {
                arrayList.add(entry.getKey());
            }
        }
        return arrayList;
    }

    private void putArray(int[] arr, Map<Integer, Integer> map) {
        for (int i = 0; i < arr.length; i++) {
            if (map.containsKey(arr[i])) {
                int n = map.get(arr[i]) + 1;
                map.put(arr[i], n);
            } else {
                map.put(arr[i], 1);
            }
        }
    }
}
```
