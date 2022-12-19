```
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {

        int n = A.size();
        if (n < 3)
            return {-1, -1};

        // s为A中1的个数。如果存在合法分法，那么三个子数组中1的个数应该相同
        int s = 0;
        for (int i=0; i<n; i++)
            s += A[i];
        // 如果没有1，则{0, n-1}是一个合法分割
        if (s == 0)
            return {0, n-1};
        // 如果s不能整除3，则没有合法分法
        if (s % 3 != 0)
            return {-1, -1};
        // 每个子数组中应含有t个1
        int t = s / 3;

        // firstOne[0]：第一个1出现的位置；firstOne[1]：第t+1个1出现的位置；firstOne[2]：第t*2+1个1出现的位置
        int firstOne[3] = {-1, -1, -1}, p = 0, count = 0;
        for (int i=0; i<n; i++){
            if (count % t == 0 && A[i])
                firstOne[count / t] = i;
            count += A[i];
        } 

        // 如果存在合法的分法{i',j'}，那么A[0...i']和A[i'+1...j'-1]的去0后缀一定都和A[firstOne[2]...n-1]相同
        // A[0...i']的去0后缀为A[firstOne[0]...i']，A[i'+1...j'-1]的去0后缀为A[firstOne[1]...j'-1]
        // 因此只需判断A[firstOne[0]...i'], A[firstOne[1]...j'-1], A[firstOne[2]...n-1]是否相同即可
        int i = firstOne[0], j = firstOne[1], k = firstOne[2];
        while(i < firstOne[1] && j < firstOne[2] && k < n){
            if (A[i] != A[j] || A[j] != A[k])
                return {-1, -1};
            i ++;
            j ++;
            k ++;
        }
        if (k == n)
            return {i-1, j};
        else
            return {-1, -1};

    }
};
```
