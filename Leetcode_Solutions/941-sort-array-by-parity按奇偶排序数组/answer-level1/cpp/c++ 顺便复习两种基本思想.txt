// 暴力原始思想
```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> dou, sin;
        int i =0, j=0, n = A.size();
        for(int i =0; i<A.size(); i++)
        {
            if(A[i]%2 == 0) dou.push_back(A[i]);
            else sin.push_back(A[i]);
        }
        for(int i =0; i<sin.size(); i++)
        {
            dou.push_back( sin[i] );
        }
        return dou;
    }
};
```


// LC.283题思路双指针遍历，j 慢指针， i快指针
// 一种放在前面 一种放在后面  check(nums[i])满足放在前面的条件  swap(nums[i] , nums[j++])

```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i =0, j=0, n = A.size();
        for(int i=0; i<n; i++)
        {
            if(A[i]%2 == 0) swap(A[i], A[j++]);
        }
        return A;
    }
};
```


// 快排思想
//分别前后指针 i, j。 如果nums[i]为偶数 i向后++ 直到出现奇数  。 如果nums[j]为偶数 j向前 直到出现偶数 交换nums[i], nums[j]. 同时都要满足的条件就是 i<j

```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int i = 0 , j = n - 1;
        while(i<j)
        {
            while(i<j && A[i]%2 == 0) i++;
            while(i<j && A[j]%2 == 1) j--;
            swap(A[i] , A[j]);
        }
        return A;
    }
};

```
