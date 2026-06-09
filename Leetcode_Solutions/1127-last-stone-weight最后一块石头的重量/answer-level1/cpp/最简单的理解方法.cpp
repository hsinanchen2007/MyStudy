### 解题思路
比较好理解的一种方法,排序,始终用第一个减去第二个,然后第二个变为0
假如 2 6 4 9 
排序后 9 6 4 2
第一次循环(-6) 0 3 4 2,然后排序4 3 2 0
第二次循环 (-3) 1 0 2 0,排序 2 1 0 0
第三次循环(-1) 1 0 0 0,然后第一个就是了

### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()<=1)
        {
            return stones[0];
        }
        sort(stones.begin(),stones.end(),greater<int>());
        int len=stones.size();
        while(len--)
        {
            stones[0]=stones[0]-stones[1];
            stones[1]=0;
            sort(stones.begin(),stones.end(),greater<int>());
        }
        return stones[0];
    }
};
```