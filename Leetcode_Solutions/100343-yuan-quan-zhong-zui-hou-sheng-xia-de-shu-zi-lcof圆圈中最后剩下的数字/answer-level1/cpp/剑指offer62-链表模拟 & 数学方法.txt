## 链表模拟(超时)
### 解题思路
最直白的方法就是使用链表进行模拟
把所有元素放到链表中，一个个走，然后删除。知道删除完为止，拿到最后一个删除的元素

### 代码
```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        list<int> nums;
        for (int i = 0; i < n; i++) {
            nums.push_back(i);
        }
        auto it = nums.begin();
        int ret = *it;
        while (!nums.empty()) {
            for (int i = 0; i < m - 1; i++) {
                it++;
                if (it == nums.end()) it = nums.begin();  // 循环
            }
            ret = *it;
            it = nums.erase(it);  // list erase 操作返回后序的迭代器
            if (it == nums.end()) it = nums.begin();  // 循环
        }
        return ret;
    }
};
```

## 数学
### 解题思路
约瑟夫环经典问题。
$f(n)代表第n个人中，存活到最后的人的最终下标$
最终剩下一个人时的安全位置肯定为0，反推安全位置在人数为n时的编号
人数为1： f(1) = 0
人数为2： f(2) = (0 + m) % 2
人数为3： f(3) = ((0+m) % 2 + m) % 3
人数为4： f(4) = (((0+m) % 2 + m) % 3 + m) % 4
... 
人数为n: $f(n) = (f(n-1) + m) % n$

### 递归方式代码
```cpp
class Solution {
public:
    int m;
    int f(int n) {
        if (n == 1) return 0;
        return (f(n-1) + m) % n;
    }
    
    int lastRemaining(int n, int m) {
        this->m = m;
        return f(n);
    }
};
```

### 迭代方式代码
```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ret = 0;
        for (int i = 2; i <= n; i++) {
            ret = (ret + m) % i;
        }
        return ret;
    }
};
```