### 解题思路
这题挺有意思的，目的是寻找`common character`
我们把`字符串列表A`中的第一个字符串`target`作为基准

```cpp
初始化结果列表result
for target字符串的每一个字符c:
    for target字符串之后的每一个字符串X:
        if c 在 X 中:
            则可以继续判断，并将相同的字符c置为0
            if X 是 A 中的最后一个字符串:
                将c加入result列表中
        if c 不在X中：
            则break掉此次循环，跳转到对下一个字符的查找
```

### 代码不那么完善，但还是AC了

```cpp
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        string target = A[0];
        int pos;
        string temp;
        for(auto c : target){
            for(int i = 1; i < A.size(); i++){
                pos = A[i].find(c);
                if(pos < 0)
                    break;
                else{
                    if(i == (A.size()-1)){
                        temp = c;
                        res.push_back(string(temp));
                    }
                    A[i][pos] = 0;
                }
            }
        }
        return res;
    }
};
```