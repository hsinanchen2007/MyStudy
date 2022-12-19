### 解题思路
栈思想，使用原数组节省内存。
从最左侧起，直到第一个>0的元素，则为安全区，该区间内行星一直向左移动，不会发生碰撞。安全区内元素不会出栈，不进行碰撞判断
非安全区元素，
(i) >0 入栈，待检验；
(ii) <0 和之前元素做加法，直到元素和>=0停止，或者到达安全区。
        如果元素和 > 0，则当前元素为栈顶；
        如果元素和==0，则出栈当前元素，并且不进行入栈操作
        如果到元素和 < 0达安全区，则入栈，将该元素扩充到安全区。
返回栈长，以及原数组。

![image.png](https://pic.leetcode-cn.com/a2f2c17d771925fc5e0cc2ee59d2b6b8f97f034a2fb237b57bb665a5326c7cc7-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize){
    int check;
    int i = 0;
    int leftSafe = -1;
    int safeCnt = 0;
    int temp;
    int now;
    /*构造安全区，左侧起所有< 0的元素 */
    for(i = 0; i < asteroidsSize; i++) {
        if(asteroids[i] < 0){
            leftSafe++;
            continue;
        }
        break;
    }
    /* now 相当于栈顶 */
    now = leftSafe;
    for(i = leftSafe + 1; i < asteroidsSize; i++){
        temp = asteroids[i];
        /* >0 的元素直接入栈 */
        if(temp > 0){
            asteroids[now + 1] = temp;
            now++;
        }else{
            check = -1;
            while(now > leftSafe){
                check = asteroids[now] + temp;
                if(check >= 0){
                    break;
                }
                now--;
            }
            if(check == 0){
                now--;
            } else if(check < 0){
                asteroids[now + 1] = temp;
                now++;
                leftSafe++;
            }
        }
    }
    *returnSize = now + 1;
    return asteroids;

}
```