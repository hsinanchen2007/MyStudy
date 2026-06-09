### 解题思路
双指针实现滑动窗口，left与right记录当前的起始与终止位置，res记录当前的最大值，p记录左右指针间1的个数，right-left+1-p即为左右指针间需要从0变为1的元素的个数，若当前变化元素的个数超过K，则移动左指针至变化元素个数等于K，如果left位置为1，则left++，p--,否则left++。

### 代码

```cpp
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res=0,p=0,left=0,right=0;
        while(right<A.size()){
            if(A[right]==1)
                p++;
            while(right-left+1-p>K){
                if(A[left]==1){
                    left++;
                    p--;
                }
                else
                    left++;
            }
            res=max(res,right-left+1);
            right++;
        }
        return res;
    }
};

```