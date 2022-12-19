### 解题思路
这是最简单的暴力法 
left 小于 target中间值 因为 mid * 2  = target 所以范围缩小
例如
15
1 2 3 4 5
那么下一次是从4开始算
4 5 6
但是其实 4 + 5 这个范围之前已经算过啦
包括不成立的
2 3 4 5 其实跟left = 1 是不是有4个重复
3 4 5 跟left =2 重复了 3 4
每一次都这样重复是很浪费且不必要的
但是我现在还在想怎么做给自己留一个问题好啦，后续回来补完的。
```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector< vector<int> > ans;
        vector<int> tarVec;
        if(target == 3)
        {
            tarVec.push_back(1);
            tarVec.push_back(2);
            ans.push_back(tarVec);
            return ans;
        }

        int left = 1, right = 2, n = 3, mid = target / 2 + 1;
        while(left < mid)
        {
            if(n == target)
            { 
                vector<int> tempLate;
                right++;
                for(int i = left; i < right; i++)
                    tempLate.push_back(i);

                ans.push_back(tempLate);

                left++;
                right = left;
                n = left;
            }
            else if(n > target)
            {
                left++;
                right = left;
                n = left;
            }

            right++;
            n += right; 
        }

        return ans;
    }
};
```


使用一种新的滑动的方式， 
例如
15
1 2 3 4 5  = 15
那么下次就是2开头
2 3 4 5 = 14
那么right 指向 5 left 指向2 ，下一个是6明细超出范围啦
所有就是left往前一位 right保持不变
3 4 5 = 12 那么right 指向 5 left 指向3 ，下一个是6明细超出范围啦
left继续往前一位 right保持不变
4 5 6 = 15 ， 满足条件
left继续往前 ， right 保持不变
5 6 = 11 那么right 指向 6 left 指向5 ，下一个是7明细超出范围啦
left继续往前一位 right保持不变
7 8 = 15   满足条件


直到 left 到 target / 2 + 1停下来

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector< vector<int> > ans;
        vector<int> tarVec;
        if(target == 3)
        {
            tarVec.push_back(1);
            tarVec.push_back(2);
            ans.push_back(tarVec);
            return ans;
        }

        int left = 1, right = 2, n = 3, mid = target / 2 + 1;
        while(left < mid)
        {
            if(n == target)
            { 
                vector<int> tempLate;
                for(int i = left; i < right + 1; i++)
                    tempLate.push_back(i);

                ans.push_back(tempLate);

                n -= left;
                left++;
            }
            else if(n > target)
            {
                n -= left;
                left++;
            }
            else
            {
                right++;
                n += right; 
            }   
        }

        return ans;
    }
};
```