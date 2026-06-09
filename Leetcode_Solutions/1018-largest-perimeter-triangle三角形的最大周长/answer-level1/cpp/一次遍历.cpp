
先把数组按序排列，然后从高的那头选出三条边，观察他们符不符合任意两边之和大于第三边的三角形形成条件，符合就直接返回和，不符合就踢掉最大值，吸收次大值。

不知道是不是调用了sort()函数的原因，效率不是很高..

执行用时 :80 ms, 在所有 C++ 提交中击败了38.93%的用户
内存消耗 :10.4 MB, 在所有 C++ 提交中击败了89.22%的用户户

等下，我tm看到提交排名最高的那个解法跟我几乎完全一样，但却是100%class的，这啥意思？？？？

```
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        
        //粗暴遍历
        sort(A.begin(), A.end());
        
        for(int i=A.size()-1; i-2>=0; i--){
            
            if(A[i]+A[i-1]<=A[i-2] || A[i-1]+A[i-2]<=A[i] || A[i]+A[i-2]<=A[i-1])
                continue;
            else{
                
                return A[i]+A[i-1]+A[i-2];
            }
            
        }
        

        
        return 0;
    }
};
```

还可以精简地写成：

也就是两个最小的边大于最长的那条边的时候返回答案

```
class Solution {
public:
    int largestPerimeter(vector<int>& A) {

        sort(A.begin(), A.end());
        
        for(int i=A.size()-1; i-2>=0; i--){
            
            if(A[i-1]+A[i-2]>A[i])
                return A[i]+A[i-1]+A[i-2];
        }
        

        
        return 0;
    }
};
```
