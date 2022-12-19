![image.png](https://pic.leetcode-cn.com/459878ed89e2cf784262553ccd0862d5a292b19c8b94acc6b534411bedd5b787-image.png)

```
    List<Integer>[] tl = new ArrayList[26];
    public boolean isSubsequence(String s, String t) {
        for(int i = 0; i < 26; i++) {
            tl[i] = new ArrayList<Integer>();
        }
        for(int i = 0; i < t.length(); i++) {
            tl[t.charAt(i) - 'a'].add(i);
        }
        return check(s);
    }
    public boolean check(String s) {
        int c = -1;
        for(int i = 0; i < s.length(); i++) {
            c = bs(tl[s.charAt(i) - 'a'], c);
            if(c == -1) {
                return false;
            }
        }
        return true;
    }
    public int bs(List<Integer> tl, int c) {
        int head = 0, tail = tl.size() - 1, mid = (head + tail) / 2;
        if(tail == -1 || tl.get(tail) <= c) {
            return -1;
        }
        while(head < tail) {
            if(tl.get(mid) > c) {
                tail = mid;
            } else if(tl.get(mid) < c) {
                head = mid;
                if(tl.get(mid + 1) > c) {
                    return tl.get(mid + 1);
                }
            } else {
                return tl.get(mid + 1);
            }
            mid = (head + tail) / 2;
        }
        return tl.get(tail);
    }
```
