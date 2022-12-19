### 解题思路
核心逻辑
1.判断是否可以插入当前位置的字符串
2.如果未出现重复字符，则可以，分两种情况
2.1 插入当前位置的字符串，begin+1，继续递归
2.2 不插入当前位置的字符串，begin+1，继续递归
3.如果不行，begin+1，继续递归

判断字符串是否重复逻辑：
1）用1个int有32位，而26个小写字母最多26位，因此可以用int来代替map。就不会涉及DFS时map的拷贝和回溯。
2）字符串中只含有小写字母（最多只需使用26位来存储每个字符的存在状态）。开始时每位都为0，0～25位分别表示a～z）。int f = 0;
3）每来一个字符c先通过i = c-'a'获取它的对应位i，然后判断f的第i位是否为0. 如果为0，说明该位对应字符还未出现；否则该字符已存在，返回false。



### 代码

```cpp
class Solution {
public:
    int maxvalue = 0;

    void dfs(vector<string> &arr, int begin, int flag, int length)
    {
        if (begin >= arr.size()) {
            maxvalue = max(maxvalue, length);
            return;
        }

        int f = flag;
        for (auto c : arr[begin]) {
            if (f & (1 << (c - 'a'))) {
                dfs(arr, begin + 1, flag, length);
                return;
            }
            f |= (1 << (c - 'a'));
        }

        dfs(arr, begin + 1, flag, length);
        dfs(arr, begin + 1, flag | f, length + arr[begin].size());
        return;
    }

    int maxLength(vector<string> &arr)
    {
        maxvalue = 0;
        dfs(arr, 0, 0, 0);
        return maxvalue;
    }
};
```