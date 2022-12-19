
![image.png](https://pic.leetcode-cn.com/5398055ff3d940f727d51dfc4b40e3f7c2b87216c0433cf6df4f0fa9c06a9e17-image.png)

解题思路：将数组A排序，res=首末两数只差再减去2*K,若res<0,则返回0。
    int smallestRangeI(vector<int>& A, int K) {
        int res = 0;
        sort(A.begin(),A.end());
            res = A[A.size()-1]-A[0]-2*K;
            if(res>=0) return res;
            return 0;
    }
