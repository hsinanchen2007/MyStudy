### 解题思路
此处撰写解题思路

### 代码

```c
int longestMountain(int* A, int ASize){
    int left = 0;
    int i = 1;
    int res = 0;
    bool up = false;
    bool dn = false;
    
    while (left < ASize - 2) {
        i = left + 1;
        //从左到右，找上坡路
        while (i < ASize - 1 && A[i] > A[i - 1]) {
            up = true;
            i++;
        }
        //有上坡路时，从左到右，找下坡路
        while (up && i < ASize && A[i] < A[i - 1]) {
            dn = true;
            i++;
        }
        //上下坡都有，计算山峰长度
        if (up & dn) {
            res = res > (i - left) ? res : i - left;
			i--; //下一个山坡从本次山坡山脚开始
		}
        //继续找下一个山峰
		left = i;
        up = false;
        dn = false;
    }

    return res;
}
```