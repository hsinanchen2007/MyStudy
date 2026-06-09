### 解题思路
从4开始遍历到target，找出能被2*target整除的数i。这里i/2即为中间数(即与序列数相乘的积为target的数)。之所以从4开始遍历是因为i/2最小的可能为2。
然后分序列数为偶和序列数为奇的情况，按步长算出序列的第一个数字，进行赋值。判断序列数为奇偶时需要加上两个条件：即序列数取余判断以及i的奇偶判断（序列数为偶时i必定为奇，序列数为奇时i必定为偶）。必须两个条件都要满足，排除i=target的这种情况。
一次循环结束后，判断v中是否为空（防止插入空序列），若不为空说明找到了一个序列，将其插入vec。并将v进行清空。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<int> v;
        vector<vector<int>> vec;
        int num;
        for(int i = 4; i <= target; i++){
            if(2*target % i == 0){
                if((2*target/i) % 2 == 0 &&i % 2 == 1){     //序列数为偶
                     num = (i-2*target/i+1)/2;
                     if(num > 0){
                         for(int j = 0; j < 2*target/i; j++,num++){
                             v.push_back(num);
                        }
                    }
                }
                if((2*target/i) % 2 == 1 &&i % 2 == 0){       //序列数为奇
                    num = (i-2*(2*target/i/2))/2;
                    if(num > 0){
                         for(int j = 0; j < 2*target/i; j++,num++){
                             v.push_back(num);
                        }
                    }
                }
                if(!v.empty()){
                    vec.push_back(v);
                    vector<int>().swap(v);
                }               
            }
            
        }
        return vec;
    }
};
```