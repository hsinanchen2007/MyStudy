## 扁平化嵌套列表迭代器

> LeetCode 第 341 题
>
> 难度：
>
> - `中等偏困难`
>
> tags：
>
> - `栈`
> - `vector`
> - `列表遍历`
> - `迭代器`

------

## 题目描述

给定一个嵌套的整型列表。设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的项或者为一个整数，或者是另一个列表。

**示例 1:**

```cpp
输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
```

**示例 2:**

```cpp
输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,4,6]。
```

------

## 思路

> ```cpp
> /**
>  * // This is the interface that allows for creating nested lists.
>  * // You should not implement it, or speculate about its implementation
>  * class NestedInteger {
>  *   public:
>  *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
>  *     bool isInteger() const;
>  *
>  *     // Return the single integer that this NestedInteger holds, if it holds a single integer
>  *     // The result is undefined if this NestedInteger holds a nested list
>  *     int getInteger() const;
>  *
>  *     // Return the nested list that this NestedInteger holds, if it holds a nested list
>  *     // The result is undefined if this NestedInteger holds a single integer
>  *     const vector<NestedInteger> &getList() const;
>  * };
>  */
> ```

### 1. 时间均衡的栈

构造时仅仅扒一层皮就 **逆向** 堆入栈中，在用户调用 hasNext 时才做深入扒皮搜索。

这种做法比较时间均衡，如果用户搞了一个很长的列表，然后就取前边几个元素就不用了，那这种实现要高效的多。

```cpp
class NestedIterator {
private:
  stack<NestedInteger> st;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++) {
      st.push(*iter);
    }
  }

  int next() {
    auto t = st.top();
    st.pop();
    return t.getInteger();
  }

  bool hasNext() {
    while (!st.empty()) {
      auto cur = st.top();
      if (cur.isInteger()) return true;
      st.pop();
      auto curList = cur.getList();
      for (auto iter = curList.rbegin(); iter != curList.rend(); iter++) {
        st.push(*iter);
      }
    }
    return false;
  }
};
```



### 2. 头重脚轻的栈

构造时扒皮抽骨到单个数字再 push 到栈里。这样预处理很慢，但是调用时很快。有点头重脚轻。

```cpp
class NestedIterator {
private:
  stack<NestedInteger> st;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++) {
      parseData(*iter);
    }
  }
  void parseData(NestedInteger item) {
    if (item.isInteger()) {
      st.push(item);
    } else {
      auto list = item.getList();
      for (auto iter = list.rbegin(); iter != list.rend(); iter++) {
        parseData(*iter);
      }
    }
  }

  int next() {
    auto t = st.top();
    st.pop();
    return t.getInteger();
  }

  bool hasNext() {
    if (st.empty()) return false;
    return true;
  }
};
```



### 3. 头重脚轻的 vector

不用栈，用 vector 来做也可以。只是存储的时候不再是从尾到头而是从头到尾啦。

```cpp
class NestedIterator {
private:
  vector<int> v;
  int ind = 0;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto iter = nestedList.begin(); iter != nestedList.end(); iter++) {
      parseData(*iter);
    }
  }
  void parseData(NestedInteger item) {
    if (item.isInteger()) {
      v.push_back(item.getInteger());
    } else {
      auto list = item.getList();
      for (auto iter = list.begin(); iter != list.end(); iter++) {
        parseData(*iter);
      }
    }
  }

  int next() {
    return v[ind++];
  }

  bool hasNext() {
    if (ind >= v.size()) return false;
    return true;
  }
};
```

