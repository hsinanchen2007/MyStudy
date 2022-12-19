### 解题思路
1.使用两个指针 read 和 write 分别标记读和写的位置，使用anchor用于标记连续出现字符的其实位置指针。
2.read用于读取字符串，write用于写出内容，利用anchor计算相同字符的个数。
3.返回write即是压缩后字符串的长度。


### 代码

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int anchor = 0;
        int write = 0;
        
        for(int read = 0; read < chars.size();read++){
            if(read + 1 == chars.size() || chars[read + 1] !=  chars[read]){
                chars[write++] = chars[anchor];
                if(read > anchor){
                    for(char c: to_string(read - anchor + 1)){
                        chars[write++] = c;
                    }
                }
                anchor = read + 1;
            }
        }
        return write;
    }
};
```