### 解题思路
因为是n个有效的括号对，所以注定了要遍历2n长度的数组，这里将 '(' 标记为 1， 将 ')' 标记为 -1
在进行递归遍历的时候，判断左、右括号的数量，不能超过n，以及它们的和值，有效性判断就是 sum >= 0，这样括号就能成对抵消
注意一下 sum == 0 的时候，必须以左括号开始，最后一位必须以右括号结束。

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        // 给定结果字符串长度2n，假定数组以 1 1 1 -1 -1 -1 排列
        int size = 2 * n;
        int *s = new int[size];
        int arr[2] = {1, -1};
        int count_left = 0;
        int count_right = 0;
        viewTree(results, s, arr, 0, size, 0, 0, 0);
        delete [] s;
        return results;
    }

    void viewTree(vector<string> &results, int *s, int arr[2], int i, int size, int sum, 
                    int count_left, int count_right) {
        for (int m = 0; m < 2; m++) {
            s[i] = arr[m];
            // 判断是否有效
            if (i == 0) {
                // 必须首位为 1
                if (s[i] != 1)
                    continue;
            } else if (i == size - 1) {
                // 末尾为 -1
                if (s[i] != -1)
                    continue;
            }
            // 优化结果
            int new_sum = sum + s[i];
            if (new_sum > size / 2 || new_sum < 0)
                continue;
            int new_count_left = count_left + (m == 0? 1: 0);
            int new_count_right = count_right + (m == 1? 1: 0);
            if (new_count_left > size / 2 || new_count_right > size / 2)
                continue;

            // 判断是否递归
            if (i == size - 1) {
                //打印循环队列
                printf("s[%d]=%d, sum = %d\n", i, s[i], new_sum);
                if (new_sum == 0) {
                    // 输出结果
                    string tmp = generateByArr(s, size);
                    results.push_back(tmp);
                }
                continue;
            }
            viewTree(results, s, arr, i+1, size, new_sum, new_count_left, new_count_right);
        }
    }

    string generateByArr(int *s, int size) {
        string data(size, '0');
        for (int i = 0; i < size; i++) {
            if (s[i] == 1) {
                data[i] = '(';
            } else {
                data[i] = ')';
            }
        }
        return data;
    }
};
```