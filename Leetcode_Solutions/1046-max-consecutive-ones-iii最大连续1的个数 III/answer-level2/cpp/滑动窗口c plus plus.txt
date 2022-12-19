### 解题思路
[start,end]
start初始为0，end从0遍历到A.size()
左窗口移动条件 当end-start+1-(此窗口1的个数)>k 
### 代码

```cpp
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        //用来记录1的idx和个数
        //vector<int> A;
        //int K=2;
        int window_start=0;
        int max1=0;
        int result=0;
        for(int window_end=0;window_end<A.size();window_end++){
            if(A[window_end]==1) max1++;
            if(window_end-window_start+1-max1>K){
                if(A[window_start]==1) max1--;
                window_start+=1;
            }
            result=max(result,window_end-window_start+1);
        }   
        return result;
    }
};
```