```
class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        int i = 0;
        for (int j = i + 1; j < S.length() - 1; j++) {
            for (int k = j + 1; k < S.length(); k++) {
                List<Integer> res = new ArrayList<>();
                if (canSplit(S, 0, i, j, k, res))
                    return res;
            }
        }
        return new ArrayList<>();
    }
    public boolean canSplit(String S, int flag, int i, int j, int k, List<Integer> res) {
        if ((S.charAt(i) == '0' && j - i > 1) || (S.charAt(j) == '0' && k - j > 1)) {
            return false;
        }
        String num1 = S.substring(i, j);
        String num2 = S.substring(j, k);
        if (num1.length() > 10 || num2.length() > 10 
            || Long.parseLong(num1) > Integer.MAX_VALUE || Long.parseLong(num2) > Integer.MAX_VALUE)
            return false;
        String sum = Integer.toString(Integer.parseInt(num1) + Integer.parseInt(num2));
        int size = sum.length();
        if (flag == 0) {
            res.add(Integer.valueOf(S.substring(i, j)));
            res.add(Integer.valueOf(S.substring(j, k)));
        }
        if (k + size > S.length())
            return false;
        String num = S.substring(k, k + size);
        if (num.equals(sum) && k + size <= S.length())
            res.add(Integer.valueOf(S.substring(k, k + size)));
        if (!num.equals(sum))
            return false;
        if (k + size == S.length())
            return true;
        return canSplit(S, 1, j, k, k + size, res);
    }
}
```
