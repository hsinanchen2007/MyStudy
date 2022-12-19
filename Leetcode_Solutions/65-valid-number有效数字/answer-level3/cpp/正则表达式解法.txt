```cpp
class Solution {
public:
    bool isNumber(string s) {
        return regex_match(s, regex("\\s*[+-]?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)(e[+-]?[0-9]+)?\\s*"));
    }
};
```

用来消遣一下可以，实际这样做时间空间消耗太大。