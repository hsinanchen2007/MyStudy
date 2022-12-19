### 解题思路
假如给出示例输入`s=[a, b, c, d, e, f, g], k=2`,处理方法如下：
1. 将字符串下标`0`到下标`k-1`的字符串翻转，比如`ab`翻转成`ba`
2. 将字符串下标`k`到`s.size()-1`的字符串翻转，比如`cdefg`翻转成`gfedc`
3. 将字符串下标`0`到`s.size()-1`的字符串翻转，比如`bagfedc`翻转成`cdefgab`，即结果

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        int mid = n / 2;
        int i = 0;
        while(i < mid){
            char temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1]= temp;
            i++;
        }
        i = n;
        mid = (n + len) / 2;
        while(i < mid){
            char temp = s[i];
            s[i] = s[len+n-i-1];
            s[len+n-i-1] = temp;
            i++;
        }
        i = 0;
        mid = len / 2;
        while(i < mid){
            char temp = s[i];
            s[i] = s[len-i-1];
            s[len-i-1] = temp;
            i++;
        }
        return s;
    }
};
```