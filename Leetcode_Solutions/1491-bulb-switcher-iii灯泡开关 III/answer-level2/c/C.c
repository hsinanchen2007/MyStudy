### 解题思路
当前最大那盏灯的标记和点亮的灯数相比。  如果一致，就加一。 不一致就继续

### 代码

```c

#define MAX(x, y) ((x) > (y) ? (x) : (y))
int numTimesAllBlue(int* light, int lightSize){
    int ans = 0;
    int max = 0;  
    for (int i = 0; i < lightSize; i++) {
       max = MAX(max, light[i]);
        if (i + 1 == max) {
            ans++;
        }
    }
    return ans;
}
```