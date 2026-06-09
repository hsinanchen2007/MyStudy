### 方法一 链表模拟
用链表模拟整个删除过程，很可惜，cpp会超时，我看很多java的题解都可以ac

### 方法一 代码


```
class Solution {
public:
    int lastRemaining(int n, int m) {
        list<int> li;
        for(int i = 0; i < n; ++i){
            li.push_back(i);
        }
        int remove_index = 0;
        while(li.size() > 1){
            auto it = li.begin();
            remove_index = (remove_index + m - 1) % li.size();
            advance(it, remove_index);
            li.erase(it);
        }
        return li.front();
    }
};
```
### 方法二 数学方法
可以参考[题解](https://blog.***.net/n/81a858b422804183a1a51dbfd4084ebc)


### 方法二 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int last = 0;
        for(int i = 2; i <= n; ++i){
            last = (last + m) % i;
        }
        return last;
    }
};
```