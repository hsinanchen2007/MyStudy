![image.png](https://pic.leetcode-cn.com/041ef37c279f610d12593a2ba9452d308e04592a73e8f986f6a627ab78874d06-image.png)

### 解题思路
参考了大佬的解答，数据太好看了，忍不住晒一下。
写了点注释。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1;// 窗口左边界
        int right = 2; // 窗口右边界
        int sum = left + right; // 窗口是逐个增长的，可以实时知道窗口中的所有数的和sum
        vector<vector<int>> res;
        while(left < right && right<target/2+2){// right滑动到大于一半，显然不可能再有了。
            if(sum < target){ // sum小于target，right++， sum随之增大
                right++;
                sum += right;
            }else if(sum > target){ // sum大于target，left++，sum随之减小***
                sum -= left;
                left++;
            }else{  // 窗口sum 等于 target， 构造解。
                vector<int> res1;
                for(int i=left; i<=right; i++){
                    res1.push_back(i);
                }
                res.push_back(res1);
                
                sum -= left; // 左窗口为left的已经结束，将left往右滑，sum随之减小。
                left++;// 最终所有的解可以看成是按照left的不同来进行分类的。
            }
        }
        return res;
    }
};
```
有收获求点赞。