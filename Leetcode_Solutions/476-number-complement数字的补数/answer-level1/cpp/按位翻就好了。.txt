```c++
class Solution {
public:
  int findComplement(int num) {
    if (num == 0) return 1;
    for (int i = 0; i < 31; i++) {
      if ((1 << i) > num) break;
      num ^= (1 << i);
    }
    return num;
  }
};
```