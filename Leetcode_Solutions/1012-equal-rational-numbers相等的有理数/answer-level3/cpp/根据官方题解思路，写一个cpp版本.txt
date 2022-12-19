```
typedef long long ll;
struct Fraction {
	ll n;
	ll d;
	Fraction() {
		n = 0;
		d = 0;
	}
	Fraction (ll nn, ll dd) {
		ll g = gcd(nn, dd);
		n = nn / g;
		d = dd / g;
	}
	void add(Fraction& x) {
		ll num = d*x.n + n*x.d;
		ll den = d*x.d;
		ll g = gcd(num, den);
		n = num / g;
		d = den / g;
	}
	ll gcd(ll x, ll y) {
		while (x != 0) {
			ll temp = x;
			x = y%x;
			y = temp;
		}
		return y;
	}
};
Fraction genFraction(string s) {
	//generate fraction
	ll repeat = 0;
	ll non_repeat = 0;
	ll Integer = 0;
	int i = 0;
	while (i < s.size() && s[i] != '.') {
		Integer = Integer * 10 + s[i] - '0';
		i++;
	}
	Fraction ans(Integer, 1);
	if (i < s.size() && s[i] == '.') i++;
	int k = 0;
	while (i < s.size() && s[i] != '(') {
		non_repeat = non_repeat * 10 + s[i] - '0';
		i++;
		k++;
	}
	if (k != 0) {
		Fraction nrf(non_repeat, pow(10, k));
		ans.add(nrf);
	}
	if (i < s.size() && s[i] == '(') i++;
	int m = 0;
	while (i < s.size() && s[i] != ')') {
		repeat = repeat * 10 + s[i] - '0';
		i++;
		m++;
	}
	if (m != 0) {
		Fraction rf(repeat, pow(10, k + m) - pow(10, k));
		ans.add(rf);
	}
	return ans;
}
class Solution {
public:
	bool isRationalEqual(string S, string T) {
		Fraction sf = genFraction(S);
		Fraction tf = genFraction(T);
		return sf.n == tf.n&&sf.d == tf.d;
	}
};
```