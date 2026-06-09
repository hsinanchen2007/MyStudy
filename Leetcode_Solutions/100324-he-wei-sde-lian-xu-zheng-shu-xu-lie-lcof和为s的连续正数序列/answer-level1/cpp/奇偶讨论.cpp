### 解题思路
分为奇偶讨论

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int mid = target / 2,begin,end;
        vector<vector<int>> result;
        for(int i = 2; mid * 2 + 1 > i;){
            //if(mid * 2 == i) continue;
            if(i % 2 && !(target % i)){ // 奇数，整除
                begin = mid - i / 2;
                end = mid + i / 2;
                vector<int> item;
                for(int k = begin; k <= end; k++){
                    item.push_back(k);
                }
                result.insert(result.begin(),item);
            }else if((mid * 2 + 1) * i == target * 2){ // 偶数
                begin = mid - i/2 + 1;
                end = mid + i/2;
                vector<int> item;
                for(int k = begin; k <= end; k++){
                    item.push_back(k);
                }
                result.insert(result.begin(),item);
            }
            i++;            
            mid = target / i;
        }
        return result;
    }
};
```