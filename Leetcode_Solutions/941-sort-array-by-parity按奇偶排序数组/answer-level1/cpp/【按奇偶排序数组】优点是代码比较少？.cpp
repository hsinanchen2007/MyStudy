### 思路
1. 设置双指针
2. 如果右指针 `r` 是奇数，指针往右走
3. 否则与左指针 `l` 交换一次
4. 移动左指针 `l` 

### 答题
```C++ []
    vector<int> sortArrayByParity(vector<int>& A) 
    {
        int l = 0;
        for (int r = 0; r < A.size(); r++)
        {
            if ((A[r] & 1) != 0) continue;
            swap(A[l++], A[r]);
        }
        return A;
    }
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

**如果感觉还不错就点个赞吧~**

这是 [我的leetcode](https://github.com/AhJo53589/leetcode-cn) ，帮助我收集整理题目，可以方便的 `visual studio` 调试，欢迎关注，star

