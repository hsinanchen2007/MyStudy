### 解题思路
此处撰写解题思路

### 代码

```cpp
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    //栈模拟迭代版
    int firstBadVersion(int n) {

        stack<int> s;
        s.push(n);
        s.push(1);
        while(!s.empty()) {
            int left = s.top();
            s.pop();
            int right = s.top();
            if(left == right) 
                return left;
            s.pop();
            int mid = left + (right-left) / 2;
            if(isBadVersion(mid)) {
                s.push(mid);
                s.push(left);

            }
            else {
                s.push(right);
                s.push(mid + 1);
            }
        }
        return 1;
    }


    //递归版
    int help(int start, int end) {
        if(start == end)
            return start;
        int mid = start + (end - start) / 2;
        if(isBadVersion(mid)) {
            return help(start, mid);
        }
        else {
            return help(mid + 1, end);
        }
    }
};
```