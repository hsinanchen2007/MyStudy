如何处理连续字符类错误是关键
**1，关键的问题是添加字符、删除字符、修改字符按照什么顺序去选取，假设size是连续n个字符连在一起的长度(n >= 3, size = n)**
- 1)删除与添加字符的时候，优先处理size % 3 == 0, 1的情况，其次才处理size % 3 == 2的情况
- 2)修改的时候与上面相反，优先处理size % 3 == 2的情况，其次才处理size % 3 == 0, 1的情况

**2，如何理解**
**修改的效率最高，size % 3 == 2是修改操作正好能恰好处理的格式，不多不少**
- 1）添加与删除要把这种格式留给修改来做，且操作后最好能增加这种格式的数量
    size % 3 == 0 && size >= 6时，删除操作可以增加这个格式的数量，
    因此删除的优先级顺序为size % 3 == 0 --> size % 3 == 1 --> size % 3 == 2

    size % 3 == 1时，我们按照最优情况添加字符后变成 size % 3 == 0；
    size % 3 == 0时，我们按照最优情况添加字符后变成 size % 3 == 1；
    因此添加操作不会增加这种格式的数量，添加操作的优先是 (size % 3 == 0 或 size % 3 == 1) --> size % 3 == 2;
- 2）修改也优先去做size % 3 == 2的情况
    修改的优先级操作是size % 3 == 2 --> (size % 3 == 0 或 size % 3 == 1)

**3，其他**
- 1）当字符不够6个时，我们需要添加字符，此时也同时可以处理字符种类不够的错误与连续字符类错误
- 2）当字符多于20个时，我们需要删除字符，此时不能处理字符种类不够的错误，但能处理连续字符类错误
- 3）当字符数达成6～20之间时，我们将只修改字符，此时每次修改操作都可以处理一个字符种类不够的错误与若干个连续字符类错误

具体代码与注释如下：
```
class Solution {
public:
    int modifySizeCount(vector<map<int, int> >& size_count, int op) {
        // op == 1 : add; op == 2 : delete;  op == 3 : change
        // 删除与添加字符的时候，优先处理size % 3 == 0, 1的情况，其次才处理size % 3 == 2的情况
        // 修改的时候与上面相反，优先处理size % 3 == 2的情况，其次才处理size % 3 == 0, 1的情况
        // 这个也好理解，修改的效率最高，size % 3 == 2是修改操作正好能恰好处理的格式，不多不少
        // 添加与删除要把这种格式留给修改来做，且操作后最好能增加这种格式的数量，并且修改也优先去做这种格式
        int error_decrease = 0; // 能破坏几个连续的3序列情况
        if (op == 1) {
            for (int i = 0; i < 3; ++i) {
                if (size_count[i].empty())
                    continue;
                auto it = size_count[i].begin();
                int size = it->first;
                if (--it->second == 0)
                    size_count[i].erase(it);
                if (size == 3) {
                    error_decrease = 1;
                } else {
                    error_decrease = 2;
                }
                if (size - 2 >= 3) {
                    ++size_count[(size - 2) % 3][size - 2];
                }
                break;
            }
        } else if (op == 2) {
            for (int i = 0; i < 3; ++i) {
                if (size_count[i].empty())
                    continue;
                auto it = size_count[i].begin();
                int size = it->first;
                if (--it->second == 0)
                    size_count[i].erase(it);
                error_decrease = 1;
                if (size - 1 >= 3) {
                    ++size_count[(size - 1) % 3][size - 1];
                }
                break;
            }
        } else {
            for (int i = 2; i >= 0; --i) {
                if (size_count[i].empty())
                    continue;
                auto it = size_count[i].begin();
                int size = it->first;
                if (--it->second == 0)
                    size_count[i].erase(it);
                if (size == 3) {
                    error_decrease = 1;
                } else if (size == 4) {
                    error_decrease = 2;
                } else {
                    error_decrease = 3;
                }
                if (size - 3 >= 3) {
                    ++size_count[(size - 3) % 3][size - 3];
                }
                break;
            }
        }
        return error_decrease;
    }
    int strongPasswordChecker(string s) {
        bool has_digit = false;
        bool has_lower = false;
        bool has_upper = false;
        vector<map<int, int> > size_count(3);
        int seq_error = 0; // 就是有几个连续的3序列，比如aaa就是一个，aaaa就是2个，aaaaaa就是3个，依次类推
        int prev = 0;
        for (int i = 0; i < s.size(); ++i) {
            has_digit = has_digit || (s[i] >= '0' && s[i] <= '9');
            has_lower = has_lower || (s[i] >= 'a' && s[i] <= 'z');
            has_upper = has_upper || (s[i] >= 'A' && s[i] <= 'Z');
            if (i == 0) continue;
            int curr = i;
            if ((s[i] != s[i - 1] && (i - prev >= 3)) || (s[i] == s[i - 1] && i == s.size() - 1 && ++i - prev >= 3)) {
                ++size_count[(i - prev) % 3][i - prev];
                seq_error += i - prev - 2;
            }
            if (s[curr] != s[curr - 1]) prev = curr;
        }
        int char_error = !has_digit + !has_lower + !has_upper; // 字符类错误
        int len_error = 0; // 长度类错误 
        bool len_not_enough = true;
        if (s.size() > 20) {
            len_error = s.size() - 20;
            len_not_enough = false;
        } else if (s.size() < 6) {
            len_error = 6 - s.size();
        }
        if (seq_error + char_error + len_error == 0)
            return 0;

        int res = len_error;
        while (len_error > 0) {
            --len_error;
            if (len_not_enough) {
                // 添加字符时，修改长度类错误的同时也可以处理字符类错误
                if (char_error > 0) --char_error;
                seq_error -= modifySizeCount(size_count, 1);
            } else {
                seq_error -= modifySizeCount(size_count, 2);
            }
        }
        while (seq_error + char_error > 0) {
            ++res;
            // 处理连续3序列错误时也可以同时处理字符类错误
            if (char_error > 0) --char_error;
            seq_error -= modifySizeCount(size_count, 3);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8b8971b95731fb63fd98d96569ee9dfc88bae40e630663470441ef84ee08e43e-image.png)
