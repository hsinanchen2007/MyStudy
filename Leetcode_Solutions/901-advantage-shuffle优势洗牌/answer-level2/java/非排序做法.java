```
class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        TreeMap<Integer, Integer> cntMap = new TreeMap<>();
        for (int a: A) {
            int cnt = cntMap.getOrDefault(a, 0);
            cnt++;
            cntMap.put(a, cnt);
        }
        int[] ans = new int[A.length];
        Arrays.fill(ans, -1);
        for (int i=0; i<B.length; i++) {
            Integer key = cntMap.higherKey(B[i]);
            if (key == null) continue;
            ans[i] = key;
            int cnt = cntMap.get(key);
            cnt--;
            if (cnt == 0)
                cntMap.remove(key);
            else cntMap.put(key, cnt);
        }
        int p = 0;
        for (int key: cntMap.keySet()) {
            int cnt = cntMap.get(key);
            for (int i=0; i<cnt; i++) {
                while (p< ans.length && ans[p] != -1)
                    p++;
                ans[p] = key;
            }
        }
        return ans;
    }
}
```