时间、空间花销比暴力解法高

```
class Solution {
public:
    string defangIPaddr(string address) {
        regex pattern("([0-9]+)\\.([0-9]+)\\.([0-9]+)\\.([0-9])");
        return regex_replace(address,pattern,"$1\[\.\]$2\[\.\]$3\[\.\]$4");
    }
};
```
