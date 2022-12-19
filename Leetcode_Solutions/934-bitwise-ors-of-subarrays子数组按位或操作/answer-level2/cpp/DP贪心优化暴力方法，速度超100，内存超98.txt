首先肯定想到用暴力方法，每一项计算以本项为子数组末尾时所有或的结果，也就是从后往前和当前数字前面所有数字或操作，然后保存结果，每次或完结果放入set中，最后返回set的大小即可：
举例 [1 2 4]：
    处理1：[1 2 4], set(1)
    处理2：[3 2 4], set(1,2,3)
    处理4：[7 6 4], set(1,2,3,4,6,7)
最后结果是set大小6，代码如下：
```
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        if(n < 2) return n;
        unordered_set<int> C;
        for(int i = 0; i < n; i++) {
            for(int j = i; j >= 0; j--) {
                A[j] |= A[i];
                C.insert(A[j]);
            }
        }
        return C.size();
    }
};
```
然鹅，这个方法超时了，55555555
考虑到如果两个连续的值在一起，比如 1 2 3 3这种情况，第2个3就不用计算了，因为它和前一个3或的结果还是3；
更进一步的，如 1 2 3 3 2的最后一个2其实也不用考虑，因为2和前面3的或结果还是3。
所以每次将当前值放入set后，与前面的值一次或之前先判断被或数是否已经包含了当前值的所有1，也就是判断(A[j] & A[i]) == A[i]是否成立，最终代码如下：
```
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        if(n < 2) return n;
        unordered_set<int> C;
        for(int i = 0; i < n; i++) {
            C.insert(A[i]);
            for(int j = i - 1; j >= 0; j--) {
                if((A[j] & A[i]) == A[i]) break;
                A[j] |= A[i];
                C.insert(A[j]);
            }
        }
        return C.size();
    }
};
```
![微信图片_20200107143627.png](https://pic.leetcode-cn.com/ee23a865f4e80a59a540216f85ab45ff2408e3736cb9db4b7f00a5ed89c6083a-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200107143627.png)

