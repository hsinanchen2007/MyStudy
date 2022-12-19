![image.png](https://pic.leetcode-cn.com/756f21069f99e0b5a6de3eb4f4cc05b345f8391fcf2a812b7dc6db3204654c15-image.png)

### 解题思路
1、分别遍历所有元素，思路是：
（1）从首元素开始遍历，然后初始化的首位指针相同
（2）每次遍历的时候，如果元素不同，就移动尾指针
（3）如果元素相同，先将上次的元素标记位清0，然后移动首指针
2、标记元素使用256位进行标记（anscci码最大值，实际可用使用128）

### 代码

```c
#define ASCCI_SIZE 256

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int lengthOfLongestSubstring(char *s)
{
    int bit[ASCCI_SIZE + 1];
    int end;
    int len;

    end = 0;
    len = 0;
    memset(bit, 0x0, sizeof(bit));
    for (int index = 0; s[index] != '\0'; index++) {
        end = MAX(end, index);
        for (; s[end] != '\0'; end++) {
            if (bit[s[end]] != 0) {
                break;
            }
            bit[s[end]] = 1;
        }
        bit[s[index]] = 0;
        len = MAX(len, (end - index));
    }
    return len;
}
```