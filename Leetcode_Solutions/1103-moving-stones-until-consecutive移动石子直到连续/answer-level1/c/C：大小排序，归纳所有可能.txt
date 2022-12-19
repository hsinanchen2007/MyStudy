思路：
a,b,c三个数先按大小排序得出min，mid，max，然后分别判断三种可能性：
1.不能移动：返回[0,0]，例如 3 4 5
2.只要移动一边或只要移到中间:
最少次数=1，最大次数=(mid-min-1)+(max-mid-1)=max-min-2
例如 1 2 5（一次移动5到3即可）  
例如 1 3 5（一次移动5到2即可，这种情况容易漏掉，因为已经排序了）
3.三个数相隔一定距离的一般情况：最少次数=2（左右各一次），最大次数（计算方式同2）
代码比较长，但是结构清晰
```
int* numMovesStones(int a, int b, int c, int* returnSize){
    *returnSize = 2;
    int min, mid, max;
    int *answer = malloc(sizeof(int) * *returnSize);
    memset(answer, 0, sizeof(int) * *returnSize);
    
    //排序得出min，mid，max
    if (a > b && a > c) {
        max = a;
        if (b > c) {
            mid = b;
            min = c;
        } else {
            mid = c;
            min = b;
        }
    } else if (b > a && b > c) {
        max = b;
        if (a > c) {
            mid = a;
            min = c;
        } else {
            mid = c;
            min = a;
        }
    } else if (c > a && c > b) {
        max = c;
        if (a > b) {
            mid = a;
            min = b;
        } else {
            mid = b;
            min = a;
        }        
    }

    //情况1，不能移动直接返回
    if (min + 1 == mid && mid + 1 == max) {
        return answer;
    }

    //情况2和3，判断并计算
    answer[1] = max - min - 2;
    if (min == mid - 1 || mid == max - 1 || min == mid - 2 || mid == max - 2) {
        answer[0] = 1;
    } else {
        answer[0] = 2;
    }
    
    return answer;
}
```
