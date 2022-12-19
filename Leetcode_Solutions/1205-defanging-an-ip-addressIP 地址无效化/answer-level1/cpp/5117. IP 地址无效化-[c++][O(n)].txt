```cpp
string defangIPaddr(string address) {
    string res;
    size_t last = 0;
    size_t found = address.find('.');
    while (found != string::npos) {
        res += address.substr(last, found - last) + "[.]";
        last = found + 1;
        found = address.find('.', last);
    }
    res += address.substr(last);
    return res;
}
```
