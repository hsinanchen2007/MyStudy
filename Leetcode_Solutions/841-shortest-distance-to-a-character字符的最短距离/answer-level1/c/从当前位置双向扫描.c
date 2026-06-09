### 解题思路
此处撰写解题思路
1. 遍历
2. 从S的当前字符位置双向扫描第一个C字符
3. 左边方向的扫描结果下标差记录为index_min1, 右边为index_min2
4. 如果某个方向没有扫描到设置为 -1
5. 如果扫描到则index_min设置为扫描到的第一个C字符和当前下标的差
6. 如果其中一个方向没有扫描到, 记录另一个方向(因为题设C一定在S中)
7. 如果两个方向都扫描到, 记录下标差比较小的那个( 更近 )
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char * S, char C, int* returnSize){
    int len = strlen(S);
    int* res = (int *)malloc(sizeof(int)*(len));
    *returnSize = len;
    int index = 0;
    int index_min1, index_min2, temp;


    for (int i=0; i<len; i++){
        index_min1 = index_min2 = -1;

        temp = i;
        for (;temp >= 0; temp--){
            if (S[temp] == C){
                index_min1 = i - temp;
                break;
            }
        }

        temp = i;
        for (;temp < len; temp++){
            if (S[temp] == C){
                index_min2 = temp - i;
                break;
            }
        }

        if (index_min1 < 0) { res[index++] = index_min2; }
        else if (index_min2 < 0 ){ res[index++] = index_min1; }
        else{res[index++] = index_min1 < index_min2 ? index_min1 : index_min2;}
    }
    return res;
}
```