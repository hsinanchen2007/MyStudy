## 思路

#### 1. 暴力法

```cpp
class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    if (num_people == 0) return {};
    vector<int> ans(num_people, 0);
    int i = 0;
    int cur = 1;
    while (candies > 0) {
      if (candies >= cur) {
        ans[i] += cur;
        candies -= cur;
        cur++;
        i = (i+1) % num_people;
      } else {
        ans[i] += candies;
        break;
      }
    }
    return ans;
  }
};
```



#### 2. 数学知识解题

利用等差数列和找规律的方式。

- 首先计算前 total_line 行的总糖果数，并与 candies 进行比较，找出能够完整分配的行数，并将这些行数中的糖果通过等差数列计算直接填充。
- 然后，再将剩下的糖果填充到最后一行中去。

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :8 MB, 在所有 C++ 提交中击败了100.00%的用户

```cpp
class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    if (num_people == 0) return {};
    vector<int> ans(num_people, 0);
    if (candies == 0) return ans;
    int total_line = 0, t = 1;
    while (true) {
      int target = (t * num_people + 1) * t * num_people / 2;
      if (candies > target) {
        total_line++, t++;
      } else {
        break;
      }
    }
    if (total_line > 0) {
      for (int i = 1; i <= num_people; i++) {
        ans[i-1] = ((total_line - 1) * num_people + 2 * i) * total_line / 2;
      }
    }
    candies -= ((t-1) * num_people + 1) * (t-1) * num_people / 2;
    cout<<candies<<endl;
    int cur = total_line * num_people + 1;
    int ind = 0;
    while (candies > cur) {
      ans[ind++] += cur;
      candies -= cur;
      cur++;
    }
    ans[ind] += candies;
    return ans;
  }
};
```

