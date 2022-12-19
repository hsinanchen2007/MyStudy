# 1.分析
如果只有一个A[i]=i，通用的二分查找(*binarySearch*)即可。
但是，实际上，可能出现多个A[i]=i，此时在找到第一个A[i]=i时，要继续使用二分法往下找**不动点**，所以要使用*fixedPoint*方法。
*binarySearch*和*fixedPoint*两个方法，*fixedPoint*多出的部分，已经在注释中标明：①②③④。
# 2.代码
```
class Solution {
    public:
         int fixedPoint(vector<int>& A) {
            // 返回数组内的最小不动索引
            int left = 0;
            int right= A.size()-1;
            int mid;
            int m = INT_MAX; // ①保存最小的不动点下标
            while(left<=right){
                mid = (left+right)/2;
                if(A[mid]==mid){
                    m = min(m,mid);  // ②找到一个不动点，保存在m中
                    right = mid - 1; // ③由于可能存在更小的不动点，往左边取区间，更新right，不做return
                }else if(A[mid]>mid){
                    right = mid - 1;
                }else{
                    left = mid+1;
                }
            }
            return m!=INT_MAX?m:-1;  // ④当m!=INT_MAX时，说明找到不动点，返回m，否则返回-1
        }
       int binarySearch(vector<int>& A) {
            if(A.size()==0)
                return -1;
            int left = 0;
            int right= A.size()-1;
            int mid;
            while(left<=right){
                mid = (left+right)/2;
                if(A[mid]==mid){
                    return mid;
                }else if(A[mid]>mid){
                    right = mid - 1;
                }else{
                    left = mid+1;
                }
            }
            return -1;
        }
};
```
