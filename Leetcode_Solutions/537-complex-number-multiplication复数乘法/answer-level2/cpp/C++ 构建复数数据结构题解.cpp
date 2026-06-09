```
class Solution {
public:
    struct Complex {
        int re;
        int im;
        Complex(int r, int i) : re(r), im(i) {};
        Complex operator * (const Complex& other) {
            int r = re * other.re - im * other.im;
            int i = re * other.im + im * other.re;
            return Complex(r, i);
        }
        string serial() {
            return to_string(re) + "+" + to_string(im) + "i";
        }
    };
    Complex parse(const string& s) {
        int i = s.find_first_of('+');
        int re = stoi(s.substr(0, i));
        int im = stoi(s.substr(i + 1, s.size() - 1 - i));
        return Complex(re, im);
    }
    string complexNumberMultiply(string a, string b) {
        return (parse(a) * parse(b)).serial();
    }
};
```

![image.png](https://pic.leetcode-cn.com/ad1489a1355b2026d2459037e4c2af8926310331392295b84772808bc4a08cd3-image.png)
