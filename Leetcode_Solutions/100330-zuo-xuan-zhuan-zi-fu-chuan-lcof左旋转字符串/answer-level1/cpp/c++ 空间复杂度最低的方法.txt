### 解题思路
计算每个字符转换前后的映射，利用循环链逐一拷贝。
abcdefg
cdefgab
找到对应的循环链:
a-c-e-g-b-d-f
如果n和字符串的长度不互质，则存在多条循环链，需要计算最大公约数。
最大公约数代表有几条循环链，
字符串长度/最大公约数代表每条循环链的长度。

### 代码

```cpp
class Solution {
public:
   
    string reverseLeftWords(string s, int n) {
        if(s.empty()){
            return s;
        }
        int len = s.length();
        n = n%len;
        int m = __gcd(len, n);   // number of chain
        int l = len/m;           // length of chain

        for(int i=0; i<m; i++){
            for(int j=0, pre = i; j<l-1; j++,pre+=n){
                swap(s[pre%len], s[(pre+n) %len]);
            }
        }
        return s;

    }
};
```