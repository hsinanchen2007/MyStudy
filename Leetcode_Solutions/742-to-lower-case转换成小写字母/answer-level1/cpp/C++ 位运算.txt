```c++
class Solution {
public:
    string toLowerCase(string str) {
        for (auto& c : str) {
            // A -> 65 -> 0b1000001
            // a -> 97 -> 0b1100001
            c = c | 0b100000;
        }
        return str;
    }
};
```