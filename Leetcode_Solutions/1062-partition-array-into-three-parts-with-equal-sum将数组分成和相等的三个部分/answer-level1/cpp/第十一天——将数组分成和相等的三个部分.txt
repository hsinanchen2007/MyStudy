### 解题思路

需要注意特例：[10,-10,10,-10,10,-10,10,-10]

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        int part = 0;
        int count = 0;
        for(int num:A) sum += num;
        for(int num:A){
            part += num;
            if(3*part == sum){
                part = 0;
                count++;
            }
        }
        return (count >= 3)? true:false;  //大于等于3是为了解决特例：[10,-10,10,-10,10,-10,10,-10]
    }
};
```



