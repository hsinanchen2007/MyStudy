![image.png](https://pic.leetcode-cn.com/c9728810f73a0e5210197d21ef8b67173340ba2f6bf9733e6ae8f3c6fbbf26f9-image.png)

### 解题思路
思路如下：
1、遍历所有数据，将临近可以组成盆地的位置记录下来，例如：0可以跟1组成盆地（后面计算面积需要忽略），1可以跟3组成盆地
2、然后遍历所有盆地，计算盆地面积以及里面填充内容的面积
3、将盆地面积之和相加，得到最终结果

### 代码

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int trap(int *height, int heightSize)
{
    int *sort = NULL;
    sort = malloc((heightSize + 1) * sizeof(int));
    if (sort == NULL) {
        return 0;
    }

    memset(sort, 0x0, (heightSize + 1) * sizeof(int));
    int pos;
    int find;
    pos = 0;
    find = 0;
    while (find < heightSize) {
        int cur;
        cur = 0;
        pos = find;
        for (int index = pos + 1; index < heightSize; index++) {
            if (height[index] >= height[pos]) {
                find = index;
                break;
            } else if (height[index] > cur) {
                cur = height[index];
                find = index;
            }
        }

        if (find == pos) {
            find++;
            continue;
        }
        sort[pos] = find;
    }

    int area;
    area = 0;
    for (int left = 0; left <= pos; left++) {
        if (sort[left] == 0) {
            continue;
        }

        //printf("\r\n left =%d,right=%d,[%d->%d]", left, sort[left], height[left], height[sort[left]]);
        if (sort[left] - left - 1 <= 0) {
            continue;
        }

        int remove;
        remove = 0;
        for (int right = left + 1; right < sort[left]; right++) {
            remove += height[right];
        }

        area += ((sort[left] - left - 1) * MIN(height[sort[left]], height[left]) - remove);
    }
    return area;
}
```