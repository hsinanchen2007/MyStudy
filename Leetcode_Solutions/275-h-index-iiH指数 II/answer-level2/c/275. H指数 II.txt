### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/2e8efb1600eb4e326ee6aaf3c9829475a90051a918cc5325915327a37ce13972-image.png)

### 代码

```c
#define EQ(x)  (citations[(x)] == citationsSize - (x))
#define GT(x)  (citations[(x)] > citationsSize - (x))
#define LT(x)  (citations[(x)] < citationsSize - (x))
#define GET(x) (citations[(x)] > 0 ? citationsSize - (x) : 0)

int hIndex(int* citations, int citationsSize){
    if (citations == NULL || citationsSize < 1) return 0;

    int left = 0;
    int right = citationsSize - 1;
    int middle = 0;

    if (EQ(right)) return GET(right);
    if (EQ(left)) return GET(left);

    if(GT(left)) return citationsSize;

    while (right - left > 1) {
        middle = (left + right) / 2;

        if (EQ(middle)) {
            return GET(middle);
        } else if (GT(middle)) {
            right = middle;
        } else {
            left = middle;
        }
    }

    if (GT(right)) {
        return GET(right);
    } else {
        return 0;
    }
}

/* test case
[0,1,3,5,6]

[]

[5]

[0]

[0,0,0,0,0,0,0]
[1,1,1,1,1,1,1]
[5,5,5,5,5,5,5]

[1,2,3,4,4,5,6]

[0,1,2,3,4,5,6,7,15]

[15,30,50,51,52,53]
 */
```