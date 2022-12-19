### 解题思路
双指针分别指向数组A和数组B的最后一个数字，然后依次插入到A的末端；
时间复杂度：O(m+n)；空间复杂度：O(1)；
![WechatIMG2387.jpeg](https://pic.leetcode-cn.com/8649f9b0ce05937aea0696a05b9e6e7d3d9d28fb8ea2696522f7b318fbd81e20-WechatIMG2387.jpeg)



### 代码

```cpp
class Solution {
    //双指针依次从后往前比较大小
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int t = m+n-1; //A的末尾idx(包括0)
        int i = m-1;   //A的末尾idx(不包括0)
        int j = n-1;   //B的末尾idx
        while((i>=0) && (j>=0)){  
            A[i] <= B[j] ? A[t--] = B[j--] : A[t--] = A[i--]; //比较大小，放在A末尾t
        }
        //如果A遍历完成（i=-1），B未遍历完成（j>=0）
        while(j>=0){
            A[t--] = B[j--];
        }
        //如果A未遍历完成（i>=0），B遍历完成（j=-1）
        //直接返回即可
        // return A;
    }
};
```