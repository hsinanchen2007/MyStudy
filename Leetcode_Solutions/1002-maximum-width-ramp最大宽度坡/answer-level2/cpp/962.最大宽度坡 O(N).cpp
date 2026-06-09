思路：
1、维护数组中每个数字最后出现的位置 记为pos。
2、记录大于等于i的数字最远的位置 记为mpos.
3、最后遍历数组查询大于等于A[i]的数字最后出现的位置，求解。整体复杂度O(N)
```
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int pos[50009],mpos[50009];
        memset(mpos,-1,sizeof(mpos));
        memset(pos,-1,sizeof(pos));
        int maxv = *max_element(A.begin(),A.end());
        int minv = *min_element(A.begin(),A.end());
        for(int i = 0;i < A.size(); i ++) {
            pos[A[i]] = i;
        }
        for(int j = maxv; j >= minv;j --) {
            mpos[j] = max(mpos[j+1],pos[j]);
        }
        int ans = 0;
        for(int i = 0;i < A.size(); i++) {
            if(mpos[A[i]] == -1) continue;
            ans = max(ans,mpos[A[i]] - i);
        }
        return ans;
    }
};
```
