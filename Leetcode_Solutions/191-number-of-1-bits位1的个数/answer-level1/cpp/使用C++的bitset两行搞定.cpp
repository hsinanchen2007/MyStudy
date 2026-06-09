    int hammingWeight(uint32_t n) {
        bitset<32> re(n);
        return re.count();
    }