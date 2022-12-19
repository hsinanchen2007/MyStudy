首先创建一个空的字符串 res，然后对形参进行依次循环。
如果 res 中的最后一个字符与参数中循环到的字符相等，则去掉该字符，否则添加字符。
时间复杂度：**O(n)**
空间复杂度：**O(1)**

**Java 代码如下：**
```java
public String removeDuplicates(String S) {
    StringBuilder res = new StringBuilder();
    int size = 0;
    for (int i = 0; i < S.length(); i++) {
        if(size != 0 && res.charAt(size-1) == S.charAt(i))
            res.deleteCharAt(--size);
        else{
            res.append(S.charAt(i));
            size++;
        }
    }
    return res.toString();
}
```
**C++ 代码如下：**
```C
class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        for(char c: S)
            if(res.size() && res.back() == c)
                res.pop_back();
            else
                res += c;
        return res;
    }
};
```