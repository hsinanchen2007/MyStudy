### 解题思路
这题难点在与在O(N)的时间复杂度完成，否则会超时；

要理解两点：
1：是题目的转化，前缀和的概念
2：单调队列的使用，队首和队尾的出队条件要明确

### 代码

```c

/*
    这个问题要低时间复杂度完成，需要转化一下

    原数组 ：【1, 2, -2, 3, 1,-4, 2】,转化为前缀和数组，即当前位置之前所有元素的和
    转化后 ：【1, 3, 1, 4, 5 , 1, 3】

    问题转化为：前缀和数组两个元素的差值为K，距离的最小间隔
    解决这个问题需要单调队列，C语言没有队列的结构，需要使用数组来表示
    
    单调队列：队列中元素单调递增或者单调递减
    单调队列队尾进元素时和单调栈一样，对于破坏单调性的元素直接弹出队尾

*/

int queue[50001];

int shortestSubarray(int* A, int ASize, int K){
    int sum = 0;
    int head = 0;
    int res = ASize + 1;
    int tail = 0; //单调队列的终点，即第一个可以写入的地方

    if (ASize == 0) {
        return -1;
    }
    // 完成数组转换
    int *sumArray = (int *)malloc((ASize + 1) * sizeof(int));
    sumArray[0] = 0;
    for (int i = 0; i < ASize; i++ ){
        sumArray[i+1] = sumArray[i] + A[i];
    }

    //找到最短满足条件的数组
    for (int i = 0; i < ASize + 1; i++) {
        while (head < tail) {
            //队列非空
            if (sumArray[i] < sumArray[queue[tail-1]]) {
                // 最新的元素比队尾小，影响单调性，把队尾元素弹出
                tail--;
            } else {
                break;
            }
        }
        queue[tail++] = i; //把最新的元素的index压入队列中

        // 队首弹出策略
        while(head < tail) {
            if ( (sumArray[i] - sumArray[queue[head]]) >= K ) {
                res = (res < (i - queue[head])) ? res : (i - queue[head]);
                head++;
            } else {
                break;
            }
        }
    }
    free(sumArray);
    if (res <= ASize) {
        return res;
    } else {
        return -1;
    }
}

/*
    错误解法1：找到子数组了，但是长度不是最短的，
    如何在O(N)的复杂度找到最短的

    错误解法2：暴力解法，O(n3) 对每个滑窗遍历一遍数据，超时了
    int shortestSubarray(int* A, int ASize, int K){
        int sum = 0;
        int count = 0;
        int findFlag = 0;
        for (int n = 1;n <= ASize; n++) {
            for (int i = 0; i < ASize - n + 1;i++) {
                sum = 0;
                for (int j = 0;j < n; j++) {
                    sum = sum + A[i+j];
                }

                if(sum >= K) {
                return n;
                }
            }
        }
        return -1;
    }
    解法3：对于数组中的每一个元素为起点，找到符合条件的最短长度，复杂度为O(n2), 依然超时
    int shortestSubarray(int* A, int ASize, int K){
    int sum = 0;
    int count = 0;
    int shortestLen = ASize +  1;
    for (int start = 0; start < ASize; start++) {
       sum = 0;
       count = 0;
       for(int j = start; j< ASize;  j++) {
           sum += A[j];
           count++;

           if (sum <= 0) {
               // 如果累加为负数则说明当前起点肯定不是最短子数组的起点，直接break
               break;
           }

           if (sum >= K) {
               shortestLen = (count < shortestLen) ? count : shortestLen;
               break;
           }
       }
    }
    
    if (shortestLen <= ASize) {
        return shortestLen;
    } else {
        return -1;
    }
}



*/
```