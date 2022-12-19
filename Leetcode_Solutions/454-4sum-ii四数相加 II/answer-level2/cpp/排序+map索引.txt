### 解题思路
1、排序，将4个数组排序（减少循环次数）
2、降维：先将AB求和，和作为map的key，相同和的个数作为value；
3、统计和为0的组合：将CD求和，并在map中索引与零的差值，如果存在，累加map的value;

### 代码

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int total = 0;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        unordered_map<int, int> m;
        for(int a: A){
            if(a+B[0]+C[0]+D[0] > 0)
                break;
            for(int b: B){
                if(a+b+C[0]+D[0] > 0)
                    break;
                m[a+b] += 1;
            }
        }

        for(int c: C){
            if(A[0]+B[0]+c+D[0] > 0)
                break;
            for(int d: D){
                if(A[0]+B[0]+c+d > 0)
                    break;
                auto it = m.find(0 - c - d);
                if(it != m.end())
                    total += it->second;
            }
        }

        return total;
    }
};
```