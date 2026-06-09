### 位运算：异或^
使用异或，无需再设置临时变量temp

### 原理
a ^ 0 = a
a ^ a = 0
a ^ b ^ a = (a ^ a) ^ b = b

### 双指针
头指针和尾指针不断交换元素

### while循环中的三行语句意义如下
```
s[front] = s[front] ^ s[tail]；
s[tail] = s[tail] ^ s[front] ^ s[tail] = s[front]；
s[front++] = s[front] ^ s[tail] ^ s[front] = s[tail]；
```

```
class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int front = 0, tail = s.size()-1;
        while(front < tail)
        {
            s[front] ^= s[tail];
            s[tail] ^= s[front];
            s[front++] ^= s[tail--];
        }
        
    }
};
```


