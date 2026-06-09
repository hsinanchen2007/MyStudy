### 解题思路
方法一：
1. 先排序，从小到大
2. 计算增量
执行用时 :
84 ms, 在所有 C++ 提交中击败了 50.93% 的用户
内存消耗 :
25.9 MB, 在所有 C++ 提交中击败了 20.83% 的用户

方法二：
1. 用50000大小的数组存储数字，下标表示代表的数字
2. n[]计算数字出现的次数
3. 从头到尾计算，出现次数大于1的需要进行处理，除了保留一个原本就要待在这个数字的，其他都+1。
执行用时：
52 ms
内存消耗：
25.9 MB
### 代码
方法一：
```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        //先排序
        int res=0;
        sort(A.begin(),A.end());
        for(int i=1;i<A.size();i++){
            if(A[i]<=A[i-1]){//=相等 <前面A[i-1]经过改变之后大于A[i]
                res+=A[i-1]-A[i]+1;//计算需要的增量
                A[i]=A[i-1]+1;//改变A[i]
            }
        }
        return res;
    }
};
```

方法二：
```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n[50000]={0};
        int len=A.size();
        for(int i=0;i<len;i++){
            n[A[i]]++;
        }
        int res=0;
        for(int i=0;i<50000;i++){
            if(n[i]>1){
                res=res+n[i]-1;//加上需要加的个数（要保留一个在i的数）
                n[i+1]+=n[i]-1;
                n[i]=1;
            }
        }
        return res;
    }
};
```
