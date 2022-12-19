每次取3段相同字符来计算，使用h记录处理过的字符避免重复处理。
若把h类型改为map, 则可以记录任意处理过的字符

```
class Solution {
public:
    int maxRepOpt1(string text) {
        int h[26] = { 0 };

        int mCnt = 0;
        int b1 = 0, e1 = 0, b2 = 0, e2 = 0, b3 = 0, e3 = 0;
        for (int i = 0, n = text.length(); i < n; ++i) {
            char c = text[i], k = c - 'a';
            if (h[k]) continue;
            h[k] = 1;

            b1 = i;
            e1 = b1;
            while (e1 < n && text[++e1] == c);
            i = e1 - 1;

            b2 = e1;
            while (b2 < n && text[++b2] != c);
            e2 = b2;
            while (e2 < n && text[++e2] == c);

            do {
                b3 = e2;
                while (b3 < n && text[++b3] != c);
                e3 = b3;
                while (e3 < n && text[++e3] == c);

                int v1 = e1 - b1, v2 = 0, v3 = 0;
                if (b2 < n && b2 > e1) {
                    v2 = e2 - b2;
                    if (b3 < n && b3 > e2) {
                        v3 = e3 - b3;
                    }
                    v1 += (b2 > e1 + 1) ? 1 : (v2 + (v3 ? 1 : 0));
                    v2 += (b3 > e2 + 1) ? 1 : (v3 + 1);
                    v3 += v3 ? 1 : 0;
                }
                mCnt = max(mCnt, max(v1, max(v2, v3)));

 
                b1 = b2;
                e1 = e2;
                b2 = b3;
                e2 = e3;
            } while (e3 < n);
        }
        return mCnt;
    }
};

```
