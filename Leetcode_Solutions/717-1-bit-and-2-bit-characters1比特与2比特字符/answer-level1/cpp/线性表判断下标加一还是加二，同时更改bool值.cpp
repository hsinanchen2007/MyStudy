### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool flag=true;
        for(int j=0;j<bits.size();){
            if(bits[j]==0){
                j++;
                flag=true;
            }
            else{
                 j+=2;
                 flag=false;
            }
        }
        return flag;
    }
};
```扫描数组时下标只有两种可能要么加一，要么加二；
**当前数组值为1时加2，同时修改bool值为false,因为此时若扫描完毕，字符串并不以0结束；
当前数组值为0时加1，同时修改bool值为true,若此时扫描完毕，则是以0结束。**