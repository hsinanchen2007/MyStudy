### 解题思路
直接在原始字符串上模拟就好了，这样空间效率和时间效率都挺高的
(毕竟你没开新的内存，然后也少了复制到新的数据结构中的步骤)
![image.png](https://pic.leetcode-cn.com/6e983f21121734bfa77518117b7ce042e5080d00ea5259e34080a5500688436f-image.png)

还是要注意进位时的一点小细节，这里
```
if (index == -1 && s[0] == '0') {
    s.insert(0, "1");
}
else if (index >= 0) {
    s[index] = '1';
}
```
如果你写的时候没有注意到会有越界的情况，很有可能和我一样卡在第二题 =_=
```
if (index == 0 && s[index] == '0') {
    s.insert(0, "1");
}
else {
    s[index] = '1';
}
```
### 代码

```cpp
class Solution {
    void addOne(string& s) {
        int index = s.size() - 1;

        while (index >= 0 && s[index] == '1') {
            s[index] = '0';
            index--;
        }

        if (index == -1 && s[0] == '0') {
            s.insert(0, "1");
        }
        else if (index >= 0) {
            s[index] = '1';
        }
    }

    void rightShift(string& s) {
        s.erase(s.size() - 1);
    }

public:
    int numSteps(string s) {
        int count = 0;

        while (s != "1") {
            if (s[s.size() - 1] == '1') {
                addOne(s);
            }
            else {
                rightShift(s);
            }
            count += 1;
        }
        return count;
    }
};
```