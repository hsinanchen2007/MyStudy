### 解题思路
1、用左右两个指针表示一段字符串的窗口
2、当窗口中的花销大于最大的花销，减去两个字符串对应位置的差，并移到左指针直到花销小于等于最大花销
3、取当前窗口的字符长度和之前窗口的最大值
4、移到右指针，直到达到字符串s的最大长度

### 代码

```c
#define MAX(x, y) (x) > (y) ? (x) : (y)

int equalSubstring(char * s, char * t, int maxCost){
    /* 初始result为0 */
    int result = 0; 
    int cost = 0;
    int len = strlen(s);
    int left = 0, right=0; /* 双下标指针 */
    
    while(right < len){
        cost += abs(t[right] - s[right]);
        //如果当前窗口的cost大于maxCost，右移left，缩小窗口，直到窗口的cost不大于maxCost
        while(cost > maxCost){
            cost -= abs(t[left] - s[left]);
            left ++;
        } 
        //如果当前窗口大小比上一次计算的result还大，更新result
        result = MAX(result, right - left + 1);
        /* 右指针移到，扩大窗口 */
        right++;            
    }
    return result;
}
```