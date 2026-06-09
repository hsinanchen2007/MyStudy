```
vector<unsigned> rev=[]() {
	vector<unsigned> Rev(2048,0);
	for(int i=0; i<2048; i++) Rev[i]=(Rev[i>>1]>>1)|((i&1)<<(10));
	return Rev;
}();

class Solution {
public:
	typedef unsigned long long u64;
	static const u64 MOD=1004535809,MOD2=MOD*MOD;
	u64 fastpow(u64 a, u64 k) {
		u64 base = 1;
		while(k) {
			if(k & 1) base = (base * a ) % MOD;
			a = (a * a) % MOD;
			k >>= 1;
		}
		return base % MOD;
	}
	void NTT(vector<unsigned>& a,const int op) {
		int n=a.size();
		u64 r = op == 1 ? 3 : 334845270;
		for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int k = 1; k < n; k <<= 1) {
			u64 x = fastpow(r, (MOD - 1) / (k << 1));
			for (int i = 0; i < n; i += (k << 1)) {
				u64 w = 1;
				for (int j = 0; j < k; j++) {
					u64 u = a[i + j];
					u64 v =w*a[i + j + k];
					a[i + j] = (u + v) % MOD;
					a[i + j + k] = (u - v + MOD2) % MOD;
					w =w * x % MOD;
				}
			}
		}
	}
	int triangleNumber(vector<int>& nums) {
		int n=nums.size();
        if(n<400) return triangleNumberSMALL(nums);
		vector<unsigned> c(2048,0);
		for(int num : nums) {
            if(num==0) --n;
            else ++c[num];
        }
		vector<unsigned> c2=c;
		NTT(c2,1);
		for(int i=0; i<2048; ++i) c2[i]=(u64(c2[i])*c2[i])%MOD;
		NTT(c2,-1);
		u64 inv = fastpow(2048, MOD - 2);
		for(int i=0; i<1001; ++i) c2[i]=(inv*c2[i])%MOD;
		for(int i=1; i<501; ++i) c2[2*i]-=c[i];
		for(int i=1; i<1001; ++i) c2[i]=c2[i-1]+(c2[i]/2);
		u64 ans= n*(n-1)*(n-2)/6;
		ans -= inner_product(c.begin(),c.begin()+1001,c2.begin(),0);
		return ans;
	}
    int triangleNumberSMALL(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int r=0;
        for(int k=2;k<nums.size();++k){
            int nk=nums[k];
            for(int i=0,j=k-1;i<j;--j){
                while(i<j&&nums[i]+nums[j]<=nk) ++i;
                r+=j-i;
            }
        }
        return r;
    }
};
```
