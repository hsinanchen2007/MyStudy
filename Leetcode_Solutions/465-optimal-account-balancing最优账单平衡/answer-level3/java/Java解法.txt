```
class Solution {
    public int minTransfers(int[][] transactions) {
        if (transactions == null || transactions.length == 0 || transactions[0].length == 0)
            return 0;
        Map<Integer, Integer> accountToDelta = new HashMap<Integer, Integer>();
        for (int[] transaction : transactions) {
            int from = transaction[0];
            int to = transaction[1];
            int val = transaction[2];
            if (!accountToDelta.containsKey(from)) {
                accountToDelta.put(from, 0);
            }
            if (!accountToDelta.containsKey(to)) {
                accountToDelta.put(to, 0);
            }
            accountToDelta.put(from, accountToDelta.get(from) - val);
            accountToDelta.put(to, accountToDelta.get(to) + val);
        }
        List<Integer> deltas = new ArrayList<Integer>();
        for (int delta : accountToDelta.values()) {
            if (delta != 0)
                deltas.add(delta);
        }
        int matchCount = removeMatchDeltas(deltas);
        return matchCount + minTransStartsFrom(deltas, 0);
    }

    private int removeMatchDeltas(List<Integer> deltas) {
        Collections.sort(deltas);
        int left = 0;
        int right = deltas.size() - 1;
        int matchCount = 0;
        while (left < right) {
            if (-1 * deltas.get(left) == deltas.get(right)) {
                deltas.remove(left);
                deltas.remove(right - 1);
                right -= 2;
                matchCount++;
            } else if (-1 * deltas.get(left) > deltas.get(right)) {
                left++;
            } else {
                right--;
            }
        }
        return matchCount;
    }

    private int minTransStartsFrom(List<Integer> deltas, int start) {
        int result = Integer.MAX_VALUE;
        int n = deltas.size();
        while (start < n && deltas.get(start) == 0)
            start++;
        if (start == n)
            return 0;
        for (int i = start + 1; i < n; i++) {
            if ((long) deltas.get(i) * deltas.get(start) < 0) {
                deltas.set(i, deltas.get(i) + deltas.get(start));
                result = Math.min(result, 1 + minTransStartsFrom(deltas, start + 1));
                deltas.set(i, deltas.get(i) - deltas.get(start));
            }
        }
        return result;
    }
}
```
