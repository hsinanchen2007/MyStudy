```
public:
    int getIdx(const char& c) {
        if('a' <= c && c <= 'z')  return int(c - 'a') + 26;
        if('A' <= c && c <= 'Z')  return int(c - 'A');
        return 0;
    }
    int numJewelsInStones(string J, string S) {
        int bucket[52]{0};
        for(const char& c: S) {
            int idx = getIdx(c);
            bucket[idx]++;
        }
        int res = 0;
        for(const char& c: J) {
            int idx = getIdx(c);
            res += bucket[idx];
        }
        return res;
    }
};
```
