```java
class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit) {
        int n = values.length;
        Value[] vals = new Value[n];
        for (int i = 0; i < n; i++) {
            vals[i] = new Value(values[i], labels[i]);
        }
        Arrays.sort(vals, (o1, o2) -> o2.value - o1.value);
        int num = 0;
        int sum = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (Value val : vals) {
            if (num < numWanted) {
                int use = map.getOrDefault(val.label, 0);
                if (use < useLimit) {
                    map.put(val.label, use + 1);
                    sum += val.value;
                    num++;
                }
            }
        }
        return sum;
    }

    static class Value {
        int value;
        int label;

        Value(int value, int label) {
            this.value = value;
            this.label = label;
        }
    }
}
```
