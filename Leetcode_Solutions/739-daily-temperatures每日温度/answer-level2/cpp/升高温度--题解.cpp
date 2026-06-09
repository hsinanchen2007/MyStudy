### 解题思路
1、从后往前扫描，记录每个状态
2、判断新数组的下一个元素是否大于0，大于0，再比较温度，等于0就不用比较了，因为后面没有比当前温度高的元素

### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
         vector<int> vec;
         for(int c: T){
             vec.push_back(0);
         }
         int day = 0;
         bool flag = false;
         for(int i=T.size()-2;i >= 0;i--){
          
            if(T[i] < T[i+1]){
                vec[i] = 1;
            }else{
                day = 0;
                flag = false;
                for(int j = i+1;j < vec.size();j++){
                    if(vec[j] > 0){
                        if(T[j+1] > T[i]){
                            day = j+1 - i;
                            break;
                        }
                    }else{
                        break;
                    }
                }

                vec[i] = day;
                
                
            }
            
            
         }
         return vec;
    }
};
```