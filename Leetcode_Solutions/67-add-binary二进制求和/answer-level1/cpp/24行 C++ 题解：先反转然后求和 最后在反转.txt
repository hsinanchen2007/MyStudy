## 开挂的方法
直接使用库自带的字符串转整数，但是可能会溢出 不推荐

## 大数加法
这题和很多OJ上的大数加法是一样的不过是二进制而已
前面有题解说要先补零到一样长，这是没有必要的
和我们平时做的一样就可以了，从左到右计算
1. 只需要先将输入翻转，达到个位对齐的效果
2. 然后一位位加起来，使用一个变量`get`存进位
3. 最后按位遍历，直到两个都遍历完
- 如果i在字符串长度范围内，则相加然后加get
- `temp%2 + '0'`是保存的字符
- `get = temp/2`是进位
4. 最后将答案反转就可以了

## C++代码
> 10进制的话只需要把2改成10就可以了
```c++
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int a_len = a.length(), b_len = b.length();
        int max_len = max(a_len, b_len);
        int get = 0;
        int temp = 0;
        for(int i = 0;i < max_len;i++) {
            temp = 0;
            if(i < a_len) temp += a[i]-'0';
            if(i < b_len) temp += b[i]-'0';
            temp += get;
            res.push_back(temp % 2 + '0');
            get = temp / 2;
        }
        if(get != 0) {
            res.push_back(get + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
