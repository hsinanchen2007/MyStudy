![image.png](https://pic.leetcode-cn.com/25f37609e408750c547a7d8cb456ac9ecef7e1b53aa029b753ad525c06e1dc84-image.png)


```
const int MAX_BITSISE_OF_NUM = 20;

class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = 1; i <= N; i++) {
            bitset<MAX_BITSISE_OF_NUM> bitvec(i);
            string temp = bitvec.to_string();
            temp.erase(0, temp.find_first_of('1'));
            if (S.find(temp) == S.npos) return false;
        }
        return true;
    }
};
```
