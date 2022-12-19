把所有元音字母顺序存入双端队列，对双端队列的两端做交换操作，直到队列的长度小于等1。

```c++
class Solution {
public:
    string reverseVowels(string s) {
        deque<int> q;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                q.emplace_back(i);
            }
        }
        
        while(q.size() > 1) {
            swap(s[q.front()], s[q.back()]);
            q.pop_front();
            q.pop_back();
        }
        return s;
    }
};
```
