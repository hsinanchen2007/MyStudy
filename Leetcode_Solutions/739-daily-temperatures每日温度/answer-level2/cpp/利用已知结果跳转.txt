### 解题思路
从右邻居开始，直接跳到下一个比它大的，不够大再跳，比它们小的就没必要比了

### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int TSize = T.size();
        vector<int> days(TSize);
        for(int i = TSize-1;i>=0;i-=1){
            if(TSize-1==i){
                days[i] = 0;
            }
            else if(i < TSize-1){
                int k = i+1;//k是右邻居下标
                while(1){
                    if(T[i]<T[k]){
                        days[i] = k-i ; 
                        break; //k跳转到的位置比当前位置高了
                    } 
                    if(0==days[k]) {
                        days[i] = 0;
                        break; //没有一个位置比当前位置气温更高了
                    }
                    k += days[k]; //下一个比当前位置气温高的位置
                }
            }
        }
        return days;
    }
};
```