```
  public String getPermutation(int n, int k) {
        StringBuilder sb = new StringBuilder();
        //如果被使用则标记为1
        int[] book = new int[n + 1];
        while (k >= 0) {
            int m = jiechen(n - 1);
            if (m < 0) break;
            //固定第一个位置
            if (k - m <= 0) {
                for (int i = 1; i < book.length; i++) {
                    if (book[i] == 0) {
                        sb.append(i);
                        book[i] = 1;
                        break;
                    }
                }
            } else {
                int d = k / m + (k % m == 0 ? 0 : 1);
                //固定位置
                int count = 0;
                for (int i = 1; i < book.length; i++) {
                    if (book[i] == 0) {
                        count++;
                        if (count == d) {
                            sb.append(i);
                            book[i] = 1;
                            break;
                        }
                    }
                }
                k -= (d -1) * m;
            }
            //改变n;
            n--;
        }
        return sb.toString();
    }
    private int jiechen(int i) {
        if (i < 0) return -1;
        int res = 1;
        for (int j = 1; j <= i; j++) {
            res *= j;

        }
        return res;
    }
```
