java 解法 4ms

```
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> list = new ArrayList<>();
        for(int i=left; i<=right; i++) {
            if (isNumbers(i)) {
                list.add(i);
            }
        }
        return  list;
    }

    private static boolean isNumbers(int num) {
        String xx = String.valueOf(num);
        for (int i=0; i<xx.length(); i++) {
            if (xx.charAt(i) == '0') {
                return false;
            }
            if (num % Integer.valueOf(xx.charAt(i)-48) != 0) {
                return false;
            }
        }
        return true;
    }
}
```