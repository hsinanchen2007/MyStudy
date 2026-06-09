1.`[i,j)`指示的区间表示一个单词.
下次循环时跳过空格.
cpp代码如下
```cpp
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        while(i<n){
            int j=i;
            while(j<n&&s[j]!=' ')
                j++;
            reverse(s.begin()+i,s.begin()+j);
            i=j+1;
        }
        return s;
    }
};
```
2.用Python就更简单了
```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join([x[::-1] for x in s.split(" ")])
```