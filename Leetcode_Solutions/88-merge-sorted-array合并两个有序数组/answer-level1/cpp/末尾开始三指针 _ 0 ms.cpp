### 解题思路
同官方题解第三种，last指针初始化在nums1的m+n-1处，另外m，n指针从nums1, nums2末尾开始向前遍历；
这题i++和--i熟练运用可以减少代码长度；

难点在于停止条件：
n>=0, m=-1 时nums2仍未全部插入到nums1中，需要继续操作
n=-1时即表明操作完成

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m-- + --n; 
        // last = m+n-1 本来
        // m,n初始化需要都-1

        /*
        while (n>=0 && m>=0) nums1[last--] = nums1[m]>nums2[n] ? nums1[m--]:nums2[n--];

        // n>=0, m=-1 时nums2仍未全部插入到nums1中，需要继续操作
        // n=-1时即表明操作完成
        while (n>=0) nums1[last--] = nums2[n--];
        */
        
        //上述逻辑可合并如下
        while (n>=0) nums1[last--] = (m>=0 && nums1[m]>nums2[n]) ? nums1[m--]:nums2[n--];
        // c++逻辑运算符，第一个能判断结果时，第二个不会计算
        
        

    }
};

```