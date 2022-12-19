### 解题思路
分段二分求解

### 代码

```java []
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int N = mountainArr.length();
        if(N == -1)
            return -1;

        int Pindex = getPeakIndex(mountainArr, 0, N);
        if(Pindex != -1){
            if(mountainArr.get(Pindex) == target)
                return Pindex;
            // 进行二分查找
            int resUp = binarySearchUp(mountainArr, target, 0, Pindex);
            if(resUp != -1)
                return resUp;
            
            int resDown = binarySearchDown(mountainArr, target, Pindex, N);
            if(resDown != -1)
                return resDown;
        }

        return -1;
    }

    private int binarySearchUp(MountainArray M, int T, int start, int end){
        while(start < end){
            int mid = start +(end-start)/2;
            int midV = M.get(mid);
            if(midV == T)
                return mid;
            else if(midV < T)
                start = mid+1;
            else
                end = mid;
        }
        return -1;
    }

    private int binarySearchDown(MountainArray M, int T, int start, int end){
        while(start < end){
            int mid = start +(end-start)/2;
            int midV = M.get(mid);
            if(midV == T)
                return mid;
            else if(midV > T)
                start = mid+1;
            else
                end = mid;
        }
        return -1;
    }

    private int getPeakIndex(MountainArray M, int start, int end){
        // 区间查询
        while(start + 1 < end){
            int mid = start + (end-start)/2;
            int midV = M.get(mid);
            int LmidV = M.get(mid-1);
            int RmidV = M.get(mid+1);
            // 顶点
            if(LmidV<midV && midV > RmidV)
                return mid;

            // 上升阶段
            else if(LmidV < midV)
                start = mid;

            // 下降阶段
            else
                end = mid;
        }
        return -1;
    }
}
```
```python []
class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        N = mountain_arr.length()
        if N == 0:
            return -1

        Pindex = self.peakValueIndex(mountain_arr, 0, N)
        print(Pindex)
        if Pindex != -1:
            if mountain_arr.get(Pindex) == target:
                return Pindex
            resR = self.binarySearchUp(mountain_arr, target, 0, Pindex)
            if resR != -1:
                return resR
            resL = self.binarySearchDown(mountain_arr, target, Pindex, N)
            if resL != -1:
                return resL

        return -1

    def binarySearchUp(self, M, T, start, end):
        while start < end:
            mid = start + (end-start)//2
            if M.get(mid) == T:
                return mid
            elif M.get(mid) < T:
                start = mid+1
            else:
                end = mid

        return -1

    def binarySearchDown(self, M, T, start, end):
        while start < end:
            mid = start + (end-start)//2
            if M.get(mid) == T:
                return mid
            elif M.get(mid) > T:
                start = mid+1
            else:
                end = mid

        return -1

    def peakValueIndex(self, M, start, end):
        # 区间查询
        while start + 1 < end:
            mid = start + (end-start)//2
            midV, LmidV, RmidV = M.get(mid), M.get(mid-1), M.get(mid+1)
            # 顶点
            if LmidV < midV and midV > RmidV:
                return mid

            # 上升段
            elif LmidV < midV:
                start = mid

            # 下降段
            else:
                end = mid
        
        return -1
```
```c++ []
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int N = mountainArr.length();
        int Pindex = getPeakIndex(mountainArr, 0, N-1);
        if(Pindex != -1){
            if(mountainArr.get(Pindex) == target)
                return Pindex;
            // 峰值左侧, 二分查找
            int resR = binarySearchUp(target, mountainArr, 0, Pindex);
            if(resR != -1)
                return resR;
            
            // 峰值右侧, 二分查找
            int resL = binarySearchDown(target, mountainArr, Pindex, N);
            if(resL != -1)
                return resL;
        }
        return -1;
    }

    // 二分法在上升有序段查找
    int binarySearchUp(const int& T, MountainArray& M, int start, int end){
        while(start < end){
            int mid = start+(end-start)/2;
            int midV = M.get(mid);
            if(midV == T)
                return mid;
            else if(midV < T)
                start = mid+1;
            else
                end = mid;
        }
        return -1;
    }

    // 二分法在下降有序段查找
    int binarySearchDown(const int& T, MountainArray& M, int start, int end){
        while(start < end){
            int mid = start+(end-start)/2;
            int midV = M.get(mid);
            if(midV == T)
                return mid;
            else if(midV > T)
                start = mid+1;
            else
                end = mid;
        }
        return -1;
    }

    // 二分法查询山脉数组的峰值坐标
    int getPeakIndex(MountainArray &M, int start, int end){
        // 区间查询
        while(start + 1< end){
            int mid = start + (end-start)/2;
            int midV = M.get(mid);
            int LmidV = M.get(mid-1);
            int RmidV = M.get(mid+1);
            if(LmidV < midV && midV > RmidV)
                return mid;
            // 处于上升阶段
            else if(LmidV < midV)
                start = mid;
            
            else if(midV > RmidV)
                end = mid;
        }
        return -1;
    }
};
```