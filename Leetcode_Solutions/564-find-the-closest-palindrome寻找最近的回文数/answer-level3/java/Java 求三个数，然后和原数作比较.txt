先求比原数小的第一个回文数，然后求比原数大的第一个回文数，再求原数前半部分组成后半部分的回文数，三个数比大小，返回离原数大小最近的一个数。
```java
class Solution {
    public String nearestPalindromic(String n) {
        char[] arr = n.toCharArray();
        for (int i = 0, j = arr.length - 1; i < j; i ++, j --) {
            arr[j] = arr[i];
        }
        String cur = String.valueOf(arr);
        String pre = nearest(cur, false);
        String next = nearest(cur, true);
        long numl = Long.valueOf(n);
        long curl = Long.valueOf(cur);
        long prel = Long.valueOf(pre);
        long nextl = Long.valueOf(next);
        
        long d1 = Math.abs(numl - prel);
        long d2 = Math.abs(numl - curl);
        long d3 = Math.abs(numl - nextl); 
        if (numl == curl) {
            return d1 <= d3 ? pre : next;
        } else if (numl < curl) {
            return d2 < d1 ? cur : pre;
        } else {
            return d2 <= d3 ? cur : next;
        }
    }

    String nearest(String cur, boolean isRight) {
        long right = cur.length() >> 1;
        long left = cur.length() - right;
        long l = Integer.valueOf(cur.substring(0, (int)left));
        if (!isRight) l--;
        else l ++;
        if (l == 0) return right == 0 ? "0" : "9";
        StringBuilder ll = new StringBuilder(String.valueOf(l));
        StringBuilder rr = new StringBuilder(ll).reverse();
        if (right > ll.length()) rr.append(9);
        return ll.append(rr.substring(rr.length() - (int)right)).toString();
    }
}
```