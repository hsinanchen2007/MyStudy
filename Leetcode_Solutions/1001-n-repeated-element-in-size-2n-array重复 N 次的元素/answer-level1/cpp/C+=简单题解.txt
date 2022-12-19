![image.png](https://pic.leetcode-cn.com/e927ec1a52459393d452b7afaf2ea01f0d0f20ff744b3ae4bbf8c40cbfde94fe-image.png)
解题思路：逐个比较，出现相等的元素就返回。
```
    int repeatedNTimes(vector<int>& A) {
       for(int i = 0;i<A.size();++i)
       for(int j = i+1;j<A.size();++j)
          if(A[i] == A[j]) return A[i];
    return 0;
    }
```
