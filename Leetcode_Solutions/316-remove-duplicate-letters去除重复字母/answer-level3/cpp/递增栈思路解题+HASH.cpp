### 解题思路

思路：
递增栈思想解题，但也不是完全的递增栈
1、首先HASH计算下每个字符的个数，便于后续计算的时候决定某个元素要不要出栈
2、新遍历到数据时，如果当前字符小于栈顶字符并且字符串后面还有栈顶字符(上面HASH的作用)，那就直接循环出栈，并将新字符入栈
3、有个点需要注意下，如果出现重复字符的时候，检查栈内是否已经包含该元素，有的话不需要再处理，由于栈不能直接查看是否包含某个元素，这里新增一个HASH表，记录栈内存在的元素
4、遍历到最后，栈内数据就是答案，组装字符串输出
5、维持一个点，就是每进入下一次遍历的时候，栈内数据都是到目前为止合法的数据

8ms 9.6M
--- wangtao HW-2020/3/1

### 代码

```cpp
class Solution {
public:
    /*

    */
    string removeDuplicateLetters(string s) {
        map<char, int> hash;
        for (auto c : s) {
            hash[c]++;
        }
        stack<char> increst;
        map<char, int> increst_elenum;
        for (int i = 0; i < s.size(); i++) {
           // 每次的栈必然是无重复最稳定的，那么如果出现栈内重复数据的时候，不需要处理
           if (increst_elenum.count(s[i]) != 0) {
               hash[s[i]]--;
               continue;
           }
           while(!increst.empty() && s[i] <= increst.top() && hash[increst.top()] > 1) {
                hash[increst.top()]--;
                increst_elenum.erase(increst.top());
                increst.pop();
            }
            increst.push(s[i]);
            increst_elenum[s[i]] = 1;
        }
        char* ans_c = new char[increst.size() + 1];
        ans_c[increst.size()] = '\0';
        int j = increst.size() - 1;
        while(!increst.empty()) {
            ans_c[j--] = increst.top();
            increst.pop();
        }
        return string(ans_c);
    }
};
```