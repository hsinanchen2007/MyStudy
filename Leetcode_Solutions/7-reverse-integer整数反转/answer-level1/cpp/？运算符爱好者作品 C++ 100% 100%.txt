### 解题思路
？运算符爱好者作品

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        long long answer = 0;
        int flag = x >= 0 ? 1 : -1;
        x = x == INT_MIN ? 0 : x >= 0 ? x : -x;
        while(x != 0){
            answer = x % 10 + answer * 10;
            x /= 10;
        }
        answer *= flag;
        answer = (answer > INT_MAX || answer < INT_MIN) ? 0 : answer;
        return answer;
    }
};
```