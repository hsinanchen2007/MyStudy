```
class Solution {
    public int findNthDigit(int n) {
        if (n <= 9) {
            return n;
        }

        n -= 9;

        int i = 2;
        int unit = 10;
        int a;
        int b = 0;
        int c;
        int temp;
        List<Integer> result = new ArrayList<Integer>();
        while (n > 0) {
            if (i * unit * 9 > 0 && n- i * unit * 9 > 0) {
                n -= i * unit * 9;
                i++;
                unit *= 10;
                continue;
            }

            a = (n-1) / i;
            b = (n-1) % i;
            c = unit + a;


            while (c >= 10) {
                temp = c % 10;
                result.add(temp);
                c = c / 10;
            }
            result.add(c);

            return result.get(result.size() - b - 1);
        }
        return result.get(result.size() - b - 1);
    }
}
```
