### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
    if(n == 1 || n == 0){
        return 1;
    }
    vector<int> myVec;
    myVec.push_back(1);
    myVec.push_back(2);
    for (int i = 2; i < n; ++i) {
        int tmp = myVec[i - 1] + myVec[i -2];
        myVec.push_back(tmp);
    }
    return myVec.back();
}
};
```