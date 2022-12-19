### 方法一：内置函数 ###
#### 思路 ####
- C++ 的 STL 提供了`find()`函数，返回值类型是迭代器（`vector<int>::iterator`）
- Python 可以使用列表的`index()`函数，注意该函数若无法找到目标，会报错而不是返回`-1`
#### 算法 ####
- 这些函数的内部实现是暴力法，参考[相关文档](http://www.cplusplus.com/reference/algorithm/find/)
  > Compares elements until a match is found.
#### 代码 ####
```c++ []
class Solution {
public:
    int findString(vector<string>& words, string s) {
        auto it = find(words.begin(), words.end(), s);
        return it != words.end() ? it - words.begin() : -1;
    }
};
```
```python []
class Solution:
    def findString(self, words: List[str], s: str) -> int:
        try:
            return words.index(s)
        except:
            return -1
```
#### 复杂度分析 ####
- 逐个比较，故时间复杂度为`O(n)`
***
### 方法二：二分查找（迭代） ###
#### 思路 ####
- 在普通二分查找算法的基础上，增加对空串的特殊处理
#### 算法 ####
- 若`mid`对应的元素为空，则将`mid`向左或右移动（以向左移动为例）
  - 若越过边界（`mid < left`），表明两者中间都是空串，故更新`left`，进入下个循环
  - 若未越过边界，则按照通常情况处理
#### 代码 ####
```c++ []
class Solution {
public:
    int findString(vector<string>& words, string s) {
        int left = 0, right = words.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            while (words[mid].empty()) --mid;
            if (mid < left) left = (left + right) / 2 + 1;
            else if (words[mid] < s) left = mid + 1;
            else if (words[mid] > s) right = mid - 1;
            else return mid;
        }
        return -1;
    }
};
```
```python []
class Solution:
    def findString(self, words: List[str], s: str) -> int:
        left, right = 0, len(words) - 1
        while left <= right:
            mid = (left + right) // 2
            while not words[mid]: mid -= 1
            if mid < left: left = (left + right) // 2 + 1;
            elif words[mid] < s: left = mid + 1
            elif words[mid] > s: right = mid - 1
            else: return mid
        return -1
```
#### 复杂度分析 ####
- 二分查找的时间复杂度本身是`O(logn)`，但是由于存在大量空串，复杂度接近`O(n)`
***
### 方法三：二分查找（递归） ###
#### 思路 ####
- 若遇到空串，可以将`words`划分为两个子数组，分别应用二分查找
#### 算法 ####
- 若`mid`对应的元素为空，则分别计算`binarySearch(left, mid - 1)`和`binarySearch(mid + 1, right)`
  - 若两者乘积为`1`，则说明在两个子数组中都没有找到目标元素，故返回`-1`
  - 若两者乘积为非正数，则说明其中一个子数组含有目标元素，故返回两者乘积的相反数
  - 综合以上两种情况，返回`-binarySearch(left, mid - 1) * binarySearch(mid + 1, right)`即可
#### 代码 ####
```c++ []
class Solution {
public:
    int findString(vector<string>& words, string s) {
        struct function {
            vector<string> &words;
            string &s;
            function(vector<string>& words, string& s) : words(words), s(s) {}
            int operator()(int left, int right) {
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (words[mid].empty())
                        return -this->operator()(left, mid - 1) * this->operator()(mid + 1, right);
                    if (words[mid] < s) left = mid + 1;
                    else if (words[mid] > s) right = mid - 1;
                    else return mid;
                }
                return -1;
            }
        } binarySearch(words, s);
        return binarySearch(0, words.size() - 1);
    }
};
```
```python []
class Solution:
    def findString(self, words: List[str], s: str) -> int:
        def helper(left = 0, right = len(words) - 1):
            while left <= right:
                mid = (left + right) / 2
                if not words[mid]:
                    return -helper(left, mid - 1) * helper(mid + 1, right)
                if words[mid] == s:
                    return mid
                elif words[mid] < s:
                    left = mid + 1
                else:
                    right = mid - 1
            return -1
        return helper()
```
#### 复杂度分析 ####
- 最好情况`O(logn)`，最坏情况`O(n)`

