## 计数`O(n+range)`
数据是`[0, 40000)`，所以移动之后占的位置是`[0, 79998]`.  
但是我们并不需要`80000`大的数组，`40001`就足够了，因为`39999`位置上的次数-1加到`40000`位置上，这些数就被均匀地分布到`40000~之后`了。  
同理，我们可以记录`maxv`，到达`maxv`之后，后面的`maxv+1, maxv+2, ...`用公式算就好了。  
```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int count[40010];
        for (int i = 0; i < 40010; i++)
            count[i] = 0;
        int maxv = 0;
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            count[A[i]]++;
            maxv = maxv >= A[i] ? maxv : A[i];
        }
        
        for (int i = 0; i <= maxv; i++) {
            if (count[i] > 1) {
                count[i + 1] += count[i] - 1;
                ans += count[i] - 1;
                count[i] = 1;
            }
        }

        ans += count[maxv + 1] * (count[maxv + 1] - 1) / 2;

        return ans;
    }
};
```