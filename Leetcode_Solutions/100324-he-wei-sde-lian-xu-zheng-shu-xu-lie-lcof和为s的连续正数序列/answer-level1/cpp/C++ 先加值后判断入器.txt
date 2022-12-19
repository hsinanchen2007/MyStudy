### 解题思路
开始先加起来再说。

1.  如果当前的和sum≤target，那么就先加入一维数组。
2.  否则如果加入当前值 j 之后的和sum＞target，则看看加入 j 之前是否＝target，
是的话则二维数组push_back()一维数组，然后初始化一维数组和sum，准备下次循环。
3.  否则的话初始化一维数组和sum，准备下次循环。

用时20ms，内存消耗击败100%

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> divec;
        vector<int> ivec;
        int sum = 0;

        for(int i = 0; i < target/2; i++){
            for(int j = i+1; j < target; j++){
                sum += j;
                if(sum<=target){
                    ivec.push_back(j);
                }else{
                    if(sum - j == target) divec.push_back(ivec);
                    ivec.clear();
                    sum = 0;
                    break;
                }
            }
        }

        return divec;

    }
};
```