前面Yupi Li说的对，但是时刻有一定的特殊性，分钟数的个位数较特殊：如果所有合法数字中，有比原始时间的个位大的数字，那么替换之后就是答案；如果没有，那么最终答案中，个位数字永远取所有合法数字中的最小值。这么处理之后，情况就只剩下了 4×4×4 = 64 种。另外，对输入时间所含的重复数字做压缩也可以降低复杂度。

代码如下

```
#define DAY_TIME     (24 * 60)

class Solution {
public:
  string nextClosestTime(string time) {
    vector<int> numbers(4);
    numbers[0] = time[0] - '0';
    numbers[1] = time[1] - '0';
    numbers[2] = time[3] - '0';
    numbers[3] = time[4] - '0';
    vector<int> origin_value = numbers;

    mergeNumbers(numbers);

    vector<int> res_value(4);
    // the lowest number is special, handle it different
    for (int num : numbers) {
      if (num > origin_value[3]) {
        res_value = origin_value;
        res_value[3] = num;

        return toString(res_value);
      }
    }

    vector<int> final_res_value = origin_value;
    res_value = origin_value;
    res_value[3] = *( std::min_element(numbers.begin(), numbers.end()) );
    int min_interval = 2000;
    // Okay, walk through all possible values
    int choice = numbers.size();
    const int MAX_IDX = choice * choice * choice;
    const int equal_idx = findEqualIdx(numbers, origin_value);
    for (int idx = 0; idx < MAX_IDX; idx ++) {
      if (idx == equal_idx) {
        continue;
      }
      int i = idx / (choice * choice);
      int j = (idx % (choice * choice)) / choice;
      int k = idx % choice;

      res_value[0] = numbers[i];
      res_value[1] = numbers[j];
      res_value[2] = numbers[k];

      if (validTime(res_value)) {
        int res_interval = subtract(res_value, origin_value);
        if (res_interval < min_interval) {
          min_interval = res_interval;
          final_res_value = res_value;
        }
      }
    }

    return toString(final_res_value);
  }

  void mergeNumbers(vector<int>& numbers) {
    vector<bool> int_num(10, false);
    for (int num : numbers) {
      int_num[num] = true;
    }

    numbers.clear();
    for (int i = 0; i < 10; i++) {
      if (int_num[i]) {
        numbers.push_back(i);
      }
    }
  }

  string toString(vector<int>& res_value) {
    string res_str = std::to_string(res_value[0]) + std::to_string(res_value[1]);
    res_str += ":";
    res_str += std::to_string(res_value[2]) + std::to_string(res_value[3]);
    return res_str;
  }

  int findEqualIdx(vector<int>& numbers, vector<int>& origin_value) {
    int choice = numbers.size();
    int idx = 0;
    for (int i = 0; i < 3; i++) {
      auto p = std::find(numbers.begin(), numbers.end(), origin_value[i]);
      int pos = p - numbers.begin();
      idx = idx*choice + pos;
    }
    return idx;
  }

  // return time interval of a-b
  int subtract(std::vector<int>& a, std::vector<int>& b) {
    int a_minute = toMinute(a) + DAY_TIME;
    int b_minute = toMinute(b);
    int result = a_minute - b_minute;
    if (result > DAY_TIME) {
      result -= DAY_TIME;
    }
    return result;
  }

  bool validTime(std::vector<int>& time) {
    int hour = time[0] * 10 + time[1];
    int minute = time[2] * 10 + time[3];
    return (hour < 24) && (minute < 60);
  }

  inline int toMinute(std::vector<int>& time) {
    int hour = time[0] * 10 + time[1];
    int minute = time[2] * 10 + time[3];

    return hour * 60 + minute;
  }
};
```
