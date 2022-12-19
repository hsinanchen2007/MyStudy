### 解题思路
此处撰写解题思路

### 代码

```c
int maxTurbulenceSize(int* A, int ASize)
{
    int r = 0;
    int res = 0;

    if (ASize == 1) {
        return 1;
    }

    while (r < ASize - 1) {
        int flag = 0;
        int num = 0;
        if (A[r] > A[r + 1]) {        
            while (r < ASize - 1) {
                if (flag == 0 && A[r] > A[r + 1]) {
                    flag = 1;
                } else if (flag == 1 && A[r] < A[r + 1]) {
                    flag = 0;
                }
                else {
                    break;
                }
                r++;
                num++;
            }
        } else if (A[r] < A[r + 1]) {
            while (r < ASize - 1) {
                if (flag == 0 && A[r] < A[r + 1]) {
                    flag = 1;
                } else if (flag == 1 && A[r] > A[r + 1]) {
                    flag = 0;
                }
                else {
                    break;
                }
                r++;
                num++;
            }
        }
        
        if (res < num + 1) {
            res = num + 1;
        }

        if (num  == 0) {
            r++;
        }        
    }

    return res;
}
```