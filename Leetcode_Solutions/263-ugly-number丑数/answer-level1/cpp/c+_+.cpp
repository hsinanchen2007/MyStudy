### 解题思路


### 代码

```cpp
class Solution {
public:
    bool isUgly(int num) {
        if(num == 1)return true;
        if(num < 1) return false;
        unordered_map<int, int> map;
        map[2]++;map[3]++;map[5]++;
        for(int i = 2;i <= num / i;++i){
            if(num % i == 0){
                if(map[i] == 0) return false;
                while(num % i == 0) num /= i;
            }
        }
        if(num > 1 && map[num] == 0)return false; 
        return true;
    }
};
```