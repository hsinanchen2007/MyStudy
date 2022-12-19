### 解题思路
两种写法

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if(len <= 1)return;
        else{
            // for (int i = 0 ; i < len/2 ; i++){
            //     // 不能取等，取等会让偶数长度换两次，而且也不用处理奇数长度中心点
            //     char temp = s[len - 1 - i];
            //     s[len - 1 - i] = s[ i ];
            //     s[ i ] = temp;
            // }
            int i = 0;
            int j = len-1;
            while(i<j){//不用考虑奇偶长度的写法
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }
        return;
    }
};
```