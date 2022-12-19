### 解题思路
解法不太好，思路是用两个index表示当然push和pop的index，并且用一个数组表示当前push在栈里面数。
每次pushIndex的和popIndex一样，那么都加1.代表这个指向的数都进行push和pop。
如果不相等，则判断数组里面是否包含了toPop的数，如果不包含，则继续push进去，直到找到和toPop相同的数。如果数组包含了toPop的数，需要判断是否在数组结尾，如果不在，直接返回false，如果在，则数组中移除这个数。


### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pushIndex = 0;
        int popIndex = 0;
        vector<int> pushVector;
        
        while (popIndex < popped.size()) {
            
            auto toPop = popped[popIndex];
            if (pushIndex < pushed.size() && toPop == pushed[pushIndex]) {
                popIndex++;
                pushIndex++;
            } else {
                if (find(pushVector.begin(), pushVector.end(), toPop) == pushVector.end()) {//数组中不包含
                    while (pushIndex < pushed.size() && pushed[pushIndex] != toPop) {//继续压数据进数组
                        pushVector.emplace_back(pushed[pushIndex]);
                        pushIndex++;
                    }
                    if (pushIndex >= pushed.size()) {
                        return false;
                    }
                } else { //包含了
                    if (pushVector.back() != toPop) { //不在栈顶
                        return false;
                    } else { //在栈顶
                        pushVector.erase(pushVector.end()-1);
                        popIndex++;
                    }
                }
            }
        }
        return true;
    }
};
```