第一种思路：整个单词取出，临时存储后，倒序取出；可以用stack也可以用vector倒序取出
第二种思路：先整个字符串倒序，再一个单词一个单词倒序

觉得这道题倒不是在算法，而是复习了下可用的库函数

stringstream是个好东西，读入时自动忽略空格
reverse函数也是个好东西，将输入的iter范围内的字符首尾颠倒
split也是个好东西，直接按照空格将字符打散
vector的rbegin()和rend()也是好东西，不需要自己取size()再递减那么狼狈，直接从尾部开始复制

```
//简单写了下第二种思路
    string reverseWords(string s) {
        auto start = s.begin(); //iterator
        auto end = s.begin() + (s.size() - 1);
        while(*start == ' ') start++;
        while(*end == ' ') end--;
        reverse(start, end+1); 
        auto cur = start;
        string word{};
        while(cur <= end){
            auto iter = cur;
            while(cur <= end && *cur != ' '){
                cur++;
            }
            reverse(iter, cur);
            word += string(iter, cur) + ' ';
            while(cur <= end && *cur == ' ') cur++;
        }
        word.pop_back();
        return word;
    }
```
```
//简单写了下第一种思路
    string reverseWords(string s) {
        stringstream ss(s);
        stack<string> sstack{};
        string t;
        while(ss >> t){
            sstack.push(t);
        }
        t = "";
        while(!sstack.empty()){
            t += sstack.top() + ' ';
            sstack.pop();
        }
        t.pop_back();
        return t;
    }
```
