如下，双指针法，很简明的几行代码：

```c++ []
vector<int> sortArrayByParity(vector<int>& A) {
    for (int i = 0, j = A.size(); i < j;) 
        if (!(A[i] % 2))
            i++;
        else if (!(A[--j] % 2))  
            A[i] ^= A[j], A[j] ^= A[i], A[i++] ^= A[j];
	return A;
}
```

