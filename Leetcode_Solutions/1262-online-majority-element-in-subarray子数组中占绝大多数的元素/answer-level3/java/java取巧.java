因为数据在1~20000
```
class MajorityChecker {

        private int[] data;

        public MajorityChecker(int[] arr) {
            this.data = arr;

        }

        public int query(int left, int right, int threshold) {

            int[] counts = new int[20001];
            for (int i = left; i <= right; i++) {
                counts[data[i]]++;
                if (counts[data[i]] == threshold) {
                    return data[i];
                }
            }
            return -1;
        }
}
```

