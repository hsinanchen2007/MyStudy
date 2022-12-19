### 解题思路
思路就是source每循环一遍，计数加一
### 代码

```cpp
class Solution {
public:
    int shortestWay(string source, string target) {
        int tindex = 0;
        int sindex = 0;
        int count = 0;
        int lastTIndex = 0;
        while(sindex < source.size()){
            if(source[sindex] == target[tindex]){
                tindex++;
            }
            sindex++;

            if(sindex == source.size() && tindex != target.size()){
                if(lastTIndex == tindex)
                    return -1;

                count++;
                lastTIndex = tindex;
                sindex = 0;
            }
        }
        return count+1;
    }
};
```