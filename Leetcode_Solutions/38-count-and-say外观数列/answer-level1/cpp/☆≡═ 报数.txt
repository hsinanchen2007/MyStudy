1. 从 "1" 开始，迭代获得下一项。
2. 用迭代器，i 和 j 把第序列第 k 项分成相同符号组成的区间。
3. 第 4 项 "1211" 分为 "1" "2" "11" 三个区间。
4. 然后把区间长度放在区间符号前输出，第5项为 1"1" 1"2" 2"11"。
5. 迭代到第 n 项。
```
class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        while (--n)
            s = getNext(s);
        return s;
    }
    
    string getNext(const string &s) {
        ostringstream os;
        for (auto i = s.begin(); i != s.end(); ) {
            auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
            os << distance(i, j) << *i;
            i = j;
        }
        return os.str();
    }
};
```
