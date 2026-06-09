
```
`内联代码`
```
```
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() == 0) return b;
        if (b.length() == 0) return a;
        int alen = a.size();
        int blen = b.size();
        //将字符串补齐
        if (alen > blen) {
            while(blen < alen) {
                b = '0' + b;
                blen++;
            }
        }

        if (alen < blen) {
            while(alen < blen) {
                a = '0' + a;
                alen++;
            }
        }
        string s;
        for (int i = alen - 1; i > 0; i--) {
            a[i] = a[i] - '0' + b[i];
            //进位
            if (a[i] >= '2') {
                a[i-1] = a[i-1] + 1;
                a[i] = a[i] - 2;
            }
        }
        a[0] = a[0] - '0' + b[0];
        if (a[0] >= '2') {
            a[0] = a[0] - 2;
            a = '1' + a;
        }
        return a;

    }
};
```
