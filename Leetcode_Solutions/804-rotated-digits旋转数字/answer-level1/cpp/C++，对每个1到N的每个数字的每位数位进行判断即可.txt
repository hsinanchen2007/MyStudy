### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int rotatedDigits(int N) {
        int ans = 0;
        for(int i = 1; i <= N; i++)
        {
            if(isValidDigit(i))
                ans++;
        }
        return ans;
    }

    //判断一个数是否是有效数字
    bool isValidDigit(int x){
        bool flag = false;  //标记是否含有 2, 5, 6, 9
        while( x > 0)
        {
            int d = x % 10;
            //好数必定至少有含有 2， 5，6，9中的一个 
            if(d == 2 || d == 5 || d == 6 || d == 9)
                flag = true;
            //含有 3, 4, 7一定不是有效数字
            if(d == 3 || d == 4 || d == 7)
                return false;
            x /= 10;
        }
        return flag;
    }
};
```