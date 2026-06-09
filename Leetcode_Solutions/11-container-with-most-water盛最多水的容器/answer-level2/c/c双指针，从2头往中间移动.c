### 解题思路
此处撰写解题思路

### 代码

```c
int maxArea(int* height, int heightSize){
    int head = 0, tail = heightSize - 1;

    if (heightSize < 2)
        return 0;

    int shorter = *(height + head) <= *(height + tail) ? *(height + head) : *(height + tail);
    int max = shorter * (tail - head);

    while(head != tail) {
        if (shorter ==  *(height + head)) {
            head++;
        } else if (shorter ==  *(height + tail)) {
            tail--;
        }
        shorter = *(height + head) <= *(height + tail) ? *(height + head) : *(height + tail);
        max = shorter * (tail - head) > max ? shorter * (tail - head) : max;
    }

    return max;
}
```