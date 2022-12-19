遍历查找分隔符，插入中括号，注意IPV4地址只有三个分隔符，所以不必遍历整个字符串，三个分隔符都遍历到就可以了

代码：
```
class Solution {
public:
    string defangIPaddr(string address) {
        int num = 0;
        for (int i = 0; i < address.length(); i++) {
            if (address[i] == '.') {
                address.insert(i, 1, '[');
                address.insert(i + 2, 1, ']');
                i = i + 2;
                num++;
            }
            if (num == 3)
                break;
        }
        return address;
    }
};
```
