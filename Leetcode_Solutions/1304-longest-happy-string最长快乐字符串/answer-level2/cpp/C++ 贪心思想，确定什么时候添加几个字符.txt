### 解题思路

其实这个题应该是个简单题，需要注意的是什么时候添加几个字符就可以了
+ 每一次添加前按照剩余数量从大到小对剩余字符排序
+ 如果目标字符串`ret`的最后一个字符**不等于**当前最大剩余量的字符，则在ret末尾添加**两个**最大剩余量的字符【剩余量大于2】，否则添加一个【剩余量等于1】
+ 如果目标字符串`ret`的最后一个字符**等于**当前最大剩余量的字符，则在ret末尾添加一个另外两个字符中剩余量较大的那个字符


```cpp
class Solution {
public:
    using P = pair<char, int>;

    string longestDiverseString(int a, int b, int c) {
        string ret = "";
        vector<P> v(3);
        v[0] = make_pair('a', a); v[1] = make_pair('b', b); v[2] = make_pair('c', c);
        while (true) {
            auto cmp = [](const P & p1, const P & p2) {return p1.second > p2.second; };
            sort(v.begin(), v.end(), cmp);
            int index = 0;
            bool is_operator = false;
            if (!ret.empty() && ret.back() == v[index].first) index += 1;
            // 如果当前剩余数量最大的字符不等于 ret 的结束字符
            if (index == 0) {
                if (v[index].second >= 2) {
                    ret.insert(ret.end(), 2, v[index].first); v[index].second -= 2;                  
                    is_operator = true;
                }
                else if (v[index].second == 1) {
                    ret.insert(ret.end(), 1, v[index].first); v[index].second -= 1;
                    is_operator = true;
                }
            }
           else {
                if (v[index].second >= 1) {
                    ret.insert(ret.end(), 1, v[index].first); v[index].second -= 1;
                    is_operator = true; 
                }
            }
            // 跳出
            if (!is_operator) break;
        }
        return ret;
    }
};
```