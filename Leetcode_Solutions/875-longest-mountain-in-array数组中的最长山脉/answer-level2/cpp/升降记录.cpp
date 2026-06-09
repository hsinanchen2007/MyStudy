## 问题描述
我们把数组 `A` 中符合下列属性的任意连续子数组 `B` 称为 “山脉”：

- `B.length >= 3`

- 存在 `0 < i < B.length - 1` 使得 `B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]`

（注意：`B` 可以是 `A` 的任意子数组，包括整个数组 `A`。）

给出一个整数数组 `A`，返回最长 “山脉” 的长度。

如果不含有 “山脉” 则返回 0。

![](https://pic.leetcode-cn.com/6aaac0d86e149a5fe912b15076ca56cd978b4982c72a9549eda30bef2344a362.png)
[数组中的最长山脉](https://leetcode-cn.com/problems/longest-mountain-in-array/ "数组中的最长山脉")

## 解决方法

- 如果当前点大于等于下一个点，说明不是山脉上升的起始点，直接continue

- 经历步骤一后，说明已经找到开始“左山脚”的点了，用一个别的变量记录下当前点

- 找到“山峰”

- 找到“右山脚”，持续更新结果

```cpp
class Solution {
public:
    //[2,1,4,7,3,2,5]   5
    int longestMountain(vector<int>& A) {
        int len=0;
        int size=A.size()-1;
        int index=0;
        while(index<size){
            //cout<<index<<" ";
            if(A[index]>=A[index+1]){
                index++;
                continue;
            }
            int start=index;
            while(index<size && A[index]<A[index+1]){
                index++;
            }
            while(index<size && A[index]>A[index+1]){
                index++;
                len=max(len,index-start+1);
            }
            
        }
        return len;
    }
};
```


site:[https://liyiping.cn/](https://liyiping.cn/)