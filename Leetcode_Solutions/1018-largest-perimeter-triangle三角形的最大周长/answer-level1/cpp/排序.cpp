### 解题思路
先排序，然后固定最大的一条边c，找较小的两条边a和b，这样的好处就是已经有c+a>b和c+b>a成立，只需要找满足a+b>c的最大a和b就行了。

### 代码

```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());

        for(int i=A.size()-1;i>=2;--i)
        {
            if(A[i-1] + A[i-2] > A[i])
            {
                return A[i-1]+A[i-2]+A[i];
            }
        }
        return 0;
    }
};
```