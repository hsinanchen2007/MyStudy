执行用时 : 4 ms , 在所有 Java 提交中击败了 94.91% 的用户
内存消耗 : 36.8 MB, 在所有 Java 提交中击败了 98.75% 的用户

一次遍历不需要回溯和动态规划...
如未遇到 **\*** 直接在模式串进行字符匹配, 失败直接退出
遇到 **\*** 之后的定长模式子串 (不包含'\*'的最长子串) 先跳过所有 **\*** 用动态生成的KMP串来进行带有'?'通配符的的无回溯匹配

代码写的有点长, 献丑了...
```java
class WildCardMatcher {
  private final char[] p;
  private boolean end = false, r = false;
  private int pi = 0, pj = 0, i = 0, kmp[];
  private char[] kmpData;

  public WildCardMatcher(String partten) {
    this(partten.toCharArray());
  }

  public WildCardMatcher(char[] arr) {
    p = arr;
    init();
    r = pi >= p.length;
  }

  private void init() {
    i = 0;
    boolean star = false;
    while (pj < p.length && p[pj] == '*' ) {
      star = true;
      ++ pj;
    }
    pi = pj;
    while (pj < p.length && p[pj] != '*' ) {
      ++ pj;
    }
    kmp = null;
    kmpData = null;
    if (star) {
      kmp = new int[pj - pi];
      kmpData = new char[kmp.length];
    }
  }

  public boolean result() {
    return r;
  }

  public void update(String s) {
    for (char c : s.toCharArray()) {
      if(end) break;
      update(c);
    }
  }

  public void update(char c) {
    if (end) return;
    if(pi + i >= pj) {
      r = ( null != kmp );
      end = true;
      return;
    }
    r = false;
    char cc = p[pi + i];
    if('?' == cc || c == cc)  {
      if(null != kmp) {
        kmpData[i] = c;
        if(i > 0) {
          int back = kmp[i - 1] + 1;
          char pBack = p[pi + back];
          if( !(pBack == '?' || pBack == cc || kmpData[back] == c) ) {
            back = (kmpData[0] == c) ? 0 : -1;
          }
          kmp[i] =  back;
        } else {
          kmp[i] = -1;
        }
      }
      ++i;
      if(pi + i >= pj) {
        if(pj >= p.length) {
          r = true;
          if(null != kmp) {
            i = i > 1 ? kmp[kmp.length - 1] + 1 : 0;
            return;
          }
        }
        init();
        if(pi >= p.length) {
          r = true;
        }
      }
    } else {
      if(null != kmp) {
        while(i > 0) {
          i = kmp[i - 1] + 1;
          cc = p[pi + i];
          if(cc == '?' || cc == c) {
            ++ i;
            break;
          }
        }
      } else {
        end = true;
        return;
      }
    }
  }
}

class Solution {
  public boolean isMatch(String s, String p) {
    WildCardMatcher w = new WildCardMatcher(p);
    w.update(s);
    return w.result();
  }
}
```

