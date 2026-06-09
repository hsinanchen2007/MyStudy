假设给出数据为 a >= b >= c。其他情况也可经过排序转化为这种情况。
1. 首先拿出 c 个 'a', 'b', 'c' 进行拼接。
2. 再拿出 b-c 个 'a'，'b' 进行拼接。**此时所有 'b'，'c' 都已拼接到答案中，仅剩 a-b 个 'a' 未拼接。**
3. 然后可以通过暴力枚举将尽可能多的 'a' 插入到答案中。

完成前两步后，答案长这个样子。
![完成前两步后的字符串](https://pic.leetcode-cn.com/56932e2fdcd9890295fd61456f81516dcc36d804d72b1020760492f56b0de6ac.png)
这样插入，可以保证用两个较少的字符隔开最多的字符，从而保证总体长度最长。
代码如下：

```cpp
class Solution {
    bool check(int pos, const string &str, const string &ch) {
        string a = str;
        a.insert(pos, ch);
        for(int i = 0; i+2 < a.size(); i++) {
            if(a[i] == ch[0] && a[i+1] == ch[0] && a[i+2] == ch[0]) {
                return false;
            }
        }
        return true;
    }
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, string>> vec;
        vec.push_back(make_pair(a, string("a")));
        vec.push_back(make_pair(b, string("b")));
        vec.push_back(make_pair(c, string("c")));
        sort(vec.begin(), vec.end());
        string str;
        while(vec[0].first > 0) {
            vec[0].first --;
            vec[1].first --;
            vec[2].first --;
            str += vec[2].second;
            str += vec[1].second;
            str += vec[0].second;
        }
        while(vec[1].first > 0) {
            vec[1].first --;
            vec[2].first --;
            str += vec[2].second;
            str += vec[1].second;
        }
        while(vec[2].first > 0) {
            bool flag = false;
            for(int i = 0; i <= str.size(); i++) {
                if(check(i, str, vec[2].second)) {
                    str.insert(i, vec[2].second);
                    flag = true;
                    break;
                }
            }
            if(flag == false) {
                break;
            }
            vec[2].first --;
        }
        return str;
    }
};
```
# 如果感觉有点意思，可以关注👏[HelloNebula](http://q8b35lo57.bkt.clouddn.com/qrcode_for_gh_6e5f8557b1f8_258.jpg)👏
* **分享周赛题解**
* **分享计算机专业课知识**
* **分享C++相关岗位面试题**
* **分享专业书籍PDF**