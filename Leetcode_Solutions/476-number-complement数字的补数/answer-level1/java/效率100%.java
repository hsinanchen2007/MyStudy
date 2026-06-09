    public int findComplement(int num) {
        int res = 0, t = 0;
        while (num > 0) {
            if ((num & 1) != 1) {
                res += 1 << t;
            }
            
            num >>= 1;
            t++;
        }
        return res;
    }