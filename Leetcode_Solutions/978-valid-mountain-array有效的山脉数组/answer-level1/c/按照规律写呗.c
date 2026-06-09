### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/80fff994990c94e02b4f13549866ca58b4db225fa7c8455d6109044b82ec97e2-image.png)

### 代码

```c
bool validMountainArray(int* A, int ASize){
    int i;

    for (i = 0; i < ASize - 1 && A[i] < A[i + 1]; i++) {
    }

    if (i == 0 || i == ASize - 1) {
        return false;
    }

    while (i < ASize - 1) {
        if (A[i] <= A[i + 1]) {
            return false;
        }
        i++;
    }

    return true;
}
```