### 代码

```java
class Solution {
    public int maximumSwap(int num) {

        if (num / 10 == 0) {
            return num;
        }
        int self = num;
        List<Integer> values = new ArrayList<>();
        while (num != 0) {
            values.add(num % 10);
            num /= 10;
        }
        Collections.reverse(values);
        for (int i = 0; i < values.size(); ++i) {
            int max = -1;
            int pos = -1;
            for (int j = values.size() - 1; j > i ; --j) {
                if (values.get(j) > max) {
                    max = values.get(j);
                    pos = j;
                }
            }
            if (values.get(i) < max) {
                Collections.swap(values, i, pos);
                int ans = 0;
                for (int k = 0; k < values.size(); ++k) {
                    ans = ans * 10 + values.get(k);
                }   
                return ans;
            }
        }
        return self;
    }
}
```