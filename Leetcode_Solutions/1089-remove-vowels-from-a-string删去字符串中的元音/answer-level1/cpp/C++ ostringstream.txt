```cpp
class Solution {
public:
    string removeVowels(string S) {
        ostringstream os;
        for (auto c : S) {
            switch(c) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    break;
                default:
                    os << c;
                    break;
            }
        }
        return os.str();
    }
};
```