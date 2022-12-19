### 解题思路
没以为可以使用STL库中的stack类，所以就用数组方式来解题了，也导致最后的代码时间复杂度和空间复杂度比较大。

### 头文件
#include <vector>

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        a.insert(a.end(), x);
    }
    
    void pop() {
        if (a.size() > 0) {
            a.erase(a.end()-1);
        }       
    }
    
    int top() {
        if (a.size() > 0) {
            int temp = *(a.end()-1);
            return temp;
        }
        return -1;
    }
    
    int getMin() {
        int temp = a.size();
        if (temp > 0) {
            int min = a[0];
            for (int i=1; i<temp; i++){
                min = min<a[i]?min:a[i];
            }
            return min;
        }
        return -1;   
    }
    
private:
    vector<int> a;
};
```