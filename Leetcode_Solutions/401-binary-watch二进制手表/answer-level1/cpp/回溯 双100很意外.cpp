### 解题思路
把小时和分钟的数值分别弄成两个集合
写个回溯函数，能获取两个集合的幂集中元素个数为n的所有组合
如果num大于等于10，无合理解
小于9的话就遍历下，两个幂集，指定n分别为n1和n2，且n1 + n2 == num，然后两个结果做下组合就是答案了.
如果n1 >= 4 或者 n2 >= 6 剪枝
详见注释

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.7 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    // 支持求小时和分钟两个幂集
    // hour，如果是小时则为true
    // n，表示幂集中每个组合的元素个数
    // level，表示data集合的当前index
    // path用来每个组合的元素
    // str表示合法的组合
    void backtrack(bool hour, int n, int level, vector<int>& data, vector<int>& path, vector<int>& str) {
      // 如果path的元素数已经大于指定的n，剪枝
      if (path.size() > n) {
        return;
      }
      
      // 结束条件，对于小时和分钟的合法值判断
      if (level == data.size()) {
        if (path.size() == n) {
          int sum = 0;
          for (auto& val : path) {
            sum += val;
          }

          if (hour) {
            if (sum < 12) {
              str.push_back(sum);
            }
          } else {
            if (sum < 60) {
              str.push_back(sum);
            }
          }
        }
        
        return;
      }

      // dfs幂集
      path.push_back(data[level]);
      backtrack(hour, n, level + 1, data, path, str);
      path.pop_back();
      backtrack(hour, n, level + 1, data, path, str);
    }

    // 将小时和分钟数据连接起来
    void concat(vector<int>& hours, vector<int>& minutes, vector<string>& ans) {
      for (int i = 0; i < hours.size(); ++i) {
        string hstr = to_string(hours[i]);
        for (int j = 0; j < minutes.size(); ++j) {
          string tmp = ":";
          if (minutes[j] < 10) {
            tmp.push_back('0');
          }
          tmp.append(to_string(minutes[j]));
          ans.push_back(hstr + tmp);
        }
      }
    }

    vector<string> readBinaryWatch(int num) {
      vector<int> hours = {1, 2, 4, 8};
      vector<int> minutes = {1, 2, 4, 8, 16, 32};
      vector<int> hour_sum;
      vector<int> minute_sum;
      vector<string> ans;
      
      if (num >= 10) {
        return ans;
      }

      for (int i = 0; i <= num; ++i) {
        // 小时亮灯大于等于4或者分钟亮灯大于等于6，均为无效解，剪枝
        if (i >= 4 || num - i >= 6) continue;
        vector<int> hpath, mpath;
        hour_sum.clear();
        minute_sum.clear();
        backtrack(true, i, 0, hours, hpath, hour_sum);
        backtrack(false, num - i, 0, minutes, mpath, minute_sum);
        concat(hour_sum, minute_sum, ans);
      }      

      return ans;
    }
};
```