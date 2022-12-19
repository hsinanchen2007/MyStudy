### 解题思路
记录当前需要填充的位置数,初始为1,碰到数字就加1,碰到#号减一,位置数为0时字符串刚好结束则有效.

### 代码

```cpp
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int Seats = 1,i=0;
        int n = preorder.size();
        while(Seats && i<n){
            if(preorder[i]=='#')Seats--;
            else Seats++;
            while(i<n && preorder[i]!=',')i++;
            i += (preorder[i]==',');
        }
        return Seats==0 && i==n;
    }
};
```