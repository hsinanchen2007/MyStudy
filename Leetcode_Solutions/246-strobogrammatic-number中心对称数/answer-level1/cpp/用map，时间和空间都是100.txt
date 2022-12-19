### 解题思路
![image.png](https://pic.leetcode-cn.com/d1e2590975d76def6b83b61bb031910ab2a4c2484bbfe52d125be3125e5f40ab-image.png)

### 代码

```cpp
class Solution {
public:
    unordered_map<char,char> m;
    bool isStrobogrammatic(string num) {
        m['6']='9'; m['9']='6'; m['8']='8'; m['0']='0'; m['1']='1';
        int l=0,r=num.size()-1;
        while(l<r){
            if(m[num[l]]==num[r]){
                l++; r--;
            }
            else return false;
        }
        if(num.size()%2==1&&m[num[num.size()/2]]!=num[num.size()/2]){
            return false;
        }
        return true;
    }
};
```