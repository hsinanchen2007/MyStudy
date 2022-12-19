本题的难点在于**思考[1,2,1,2,3]中的[2,1],[2,1,2],[1,2]这些子数组是如何求出来的**，对于`[1,2],[1,2,1],[1,2,1,2],[2,3]`这些子数组求解可以利用window的size为k时求出。

当window的size等于k时，也就是window内有k个不同的整数，我们求出[left,right]这个区间的窗口内还有多少个满足题目条件的子数组。注意：这里的子数组必须是以right结尾的子数组。

比如：
[1,2,1]中以**window[right]结尾**的子数组还有[2,1]
[1,2,1,2]中以**window[right]结尾**的子数组还有[2,1,2],[1,2]

代码如下：
```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        if(A.empty()||K==0)return 0;
        
        int left=0,right=0,result=0,N=A.size();
        unordered_map<int,int> window;//窗口：K个数字->每个数字出现的次数
        
        while(right<N)
        {
            window[A[right++]]++;
            
            while(window.size()>K)//窗口溢出，需缩小窗口
            {
                if(window[A[left]]>1)window[A[left]]--;
                else window.erase(A[left]);
                left++;
            }
            
            int temp=left;//用来求必须以A[right]结尾的子数组满足题目条件的个数，对left不会产生影响。
            while(window.size()==K)//子数组中有K个不同的整数，来更新result
            {
                result++;
                if(window[A[temp]]>1)window[A[temp]]--;
                else window.erase(A[temp]);
                temp++;
            }
            
            while(temp>left)//还原子数组
            {
                window[A[temp-1]]++;
                temp--;
            }
        }
        
        return result;
    }
};
```
