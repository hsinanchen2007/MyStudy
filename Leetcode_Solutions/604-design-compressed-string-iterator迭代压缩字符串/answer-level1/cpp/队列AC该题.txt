### 解题思路
其实刚拿到时候，想了下，用什么数据结构去组织，发现队列很适合，只是需要记录<char, int>队。唯一麻烦点的就是char对应的int数在大于等于个位数上的识别;
解决上述问题后，后面思路就是一片开阔，耗时一般，后续想到好的idea再去优化吧，先mark一下。

### 代码

```cpp
class StringIterator {
public:
    StringIterator(string compressedString) {
        int  i = 0;
        while (i < compressedString.length() ) {
            char c = compressedString[i];
            if (isalpha(c)) {
                int k = 1;
                string temp ;
                while (isdigit(compressedString[i+k])) {
                    temp += compressedString[i+k];
                    k++;
                }
                i += k;
                q.push(make_pair(c, stoi(temp)));
            }
        }
    }
    
    char next() {
        if (q.empty())
            return ' ';
        pair<char, int>& s = q.front();
        s.second--;
        if (s.second == 0) {
            q.pop();
        }

        return s.first;
    }
    
    bool hasNext() {
        return (q.size());
    }
private:
    queue<pair<char, int>> q;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```