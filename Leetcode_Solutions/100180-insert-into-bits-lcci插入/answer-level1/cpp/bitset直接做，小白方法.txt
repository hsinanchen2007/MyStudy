把m和n都用bitset表示出来，然后把n的i位到j位改一下，因为bitset不能直接转成int（我没找到），所以循环一下输出最后结果


int insertBits(int N, int M, int i, int j) {
        bitset<32> n(N);
        bitset<32> m(M);
        for(int h = i ; h <= j ; h++){
            n.set(h,m[h-i]);
        }
        int res=0;
        for(int d = 0 ; d <32 ; d++){
            cout<<n[d];
            if(n.test(d)){
                res+=pow(2,d);
            }
        }
        return res;
    }