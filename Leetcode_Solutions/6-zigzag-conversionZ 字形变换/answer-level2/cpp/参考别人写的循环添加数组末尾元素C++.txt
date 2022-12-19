### 解题思路
看了这个老兄[@bian-bian-xiong](/u/bian-bian-xiong/)的题解才写出来性能比较不错的代码，我自己想的那个实在是太耗费时间。

我自己的想法是，先建设一个Z的路径方向向量，然后重复利用它，计算每一个字符的xy位置，然后把xy以及字符存放到map中，xy作为key，这样最后遍历map就可以得出正确的顺序。最后也能运行正确，但耗时比较多，打败的人在10%。

实在没有想到这么好的方法。学习了。

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        bool going_down = false;
        int curr_row = 0;
        vector<string> result_arr(numRows);
        for (char c : s) {
            result_arr[curr_row] += c;
            if (curr_row == 0 || curr_row == numRows - 1) {
                going_down = !going_down;
            }

            curr_row += going_down ? 1 : -1;
        }

        string result;
        for (string str : result_arr) {
            result += str;
        }
        return result;
    }
};
```
![微信截图_20200222172638.png](https://pic.leetcode-cn.com/0c00e3e95d1b8da4bbfeff8d540daa3b1317f820208be145b51850a0d08f8cc8-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200222172638.png)

