### 解题思路
此处撰写解题思路

### 代码
![Screen Shot 2020-04-05 at 2.05.04 PM.png](https://pic.leetcode-cn.com/efa08d16bcd12cc7c6d9e3962906651e03dc4f861bcb13212671509feeb20194-Screen%20Shot%202020-04-05%20at%202.05.04%20PM.png)

```cpp
class Solution {
private:

struct CharNode {
    char c;
    int cnt;
    CharNode(char _c, int _cnt) : c(_c), cnt(_cnt) {}
    CharNode() {}
};
public:
        void sortCharList(CharNode *charList) {
            sort(charList, charList+3, [](CharNode x, CharNode y){ return x.cnt > y.cnt;});
        }

        string longestDiverseString(int a, int b, int c) {
            CharNode charList[3] = {{'a', a},
                            {'b', b},
                            {'c', c}};
            sortCharList(charList);
            string s;
            int cur_s_idx(0);
            int tmp_idx = 0;
            int total(a+b+c);
            bool shift(false);
            while(total > 0){
                if (charList[tmp_idx].cnt > 0) {
                    if (s.length() >= 2 && s[cur_s_idx - 1] == charList[tmp_idx].c && s[cur_s_idx - 2] == charList[tmp_idx].c) {
                        sortCharList(charList);
                        if(charList[tmp_idx].c == s[cur_s_idx - 1] && charList[tmp_idx].c == s[cur_s_idx - 2]){
                            tmp_idx++;
                            shift = true;
                        }
                    } else {
                        s += charList[tmp_idx].c;//默认操作
                        --charList[tmp_idx].cnt;
                        ++cur_s_idx;
                        --total;
                        if(shift){
                            sortCharList(charList);
                            tmp_idx = 0;
                            shift = false;
                        }
                    }
                }else{
                    sortCharList(charList);
                    tmp_idx = 0;
                    if(s[cur_s_idx - 1] == charList[tmp_idx].c && s[cur_s_idx - 2] == charList[tmp_idx].c ){
                        break;
                    }
                }
            }

            return s;
        }
};
```