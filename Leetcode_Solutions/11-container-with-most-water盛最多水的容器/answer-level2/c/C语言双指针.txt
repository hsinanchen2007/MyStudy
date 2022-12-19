### 解题思路
如下代码所示
执行用时 :
16 ms
, 在所有 C 提交中击败了
94.14%
的用户
内存消耗 :
6.2 MB
, 在所有 C 提交中击败了
100.00%
的用户
### 代码

```c
int  maxArea(int* height, int heightsize) {
    int* i = height; int* j = height + heightsize - 1;
    int* ti = i; int* tj = j;
    int area = 0; int ta = 0;
    while (ti != tj) {
        //先求ta  
        if (*ti > * tj) {
            ta = *tj * (tj - ti);
            if (ta > area) { // 如果判定成功 将临时边界转为正式边界 并将较小端的临时边界向内移动一位
                area = ta; j = tj; i = ti;
            }
            tj--;
        }
        else {
            ta = *ti * (tj - ti);
            if (ta > area) { // 如果判定成功 将临时边界转为正式边界 并将较小端的临时边界向内移动一位
                area = ta; j = tj; i = ti;
            }
            ti++;
        }
    }
    return area;
}
```