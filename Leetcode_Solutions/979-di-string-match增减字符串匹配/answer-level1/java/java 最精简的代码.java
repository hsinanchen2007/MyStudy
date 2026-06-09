```
public int[] diStringMatch(String S) {
        int len = S.length();
        int[] res = new int[len + 1];
        int l = 0, r = len;
        for (int i = 0; i < len; i++) {
            if ('I' == S.charAt(i)) res[i] = l++;
            else res[i] = r--;
        }
        //最后一个数字,此时l=r
        res[len] = l;
        return res;
    }
```
