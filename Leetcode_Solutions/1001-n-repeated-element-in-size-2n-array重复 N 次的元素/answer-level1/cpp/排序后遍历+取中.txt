    本题可有多种解题思路，以下列举两种简单的方法。
    方法一：因为除了重复的元素外，其余元素均不同，所以可采取排序后遍历的方法，只要遍历到两个相同的元素，则该元素为重复 N 次的元素。代码如下：
```
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
       sort(A.begin() , A.end());
       int ans;
       for (int i = 0; i < A.size()-1; ++i){
           if (A[i] == A[i+1]){
               ans = A[i];
               break;
           }
       }
       return ans;
    }
};
```
    方法二：一共有 2N 个元素，其中一个元素重复了 N 次，那么排序后，这个元素一定在中间值附近，可通过对中间值的比较找出该元素。代码如下：
```
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
       sort(A.begin() , A.end());
       if (A[(A.size()/2)] == A[(A.size()/2)+1])
            return A[(A.size()/2)];
        else
            return A[(A.size()/2)-1];
    }
};
```