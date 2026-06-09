### 解题思路
![image.png](https://pic.leetcode-cn.com/098d5fea239629c4ee49bee92fa76ad71e18a5093c86c67e6fb9c46476e04479-image.png)

1. visit 数组，用于标记相应的数据已经被访问，默认值为 -1，表示未被访问，访问后填充start值；
2. start , cur , next 三个变量索引数组，start表示某次遍历的起点,cur表示遍历的当前点，next是将要遍历的下一个点；
3. 所有被cur访问的点，都用start值填充visit，也就是visit[cur] = start; 表示该点被以start为起点的访问链条访问过；
4. next由cur + nums[cur]进行两次 +size 取模运算，排除负数的情况；
5. 当 next == cur时，说明该点下一个要访问的是自己，不满足长度 >1 的要求，所以 break排除；
6. 当 nums[next] * nums[cur] < 0 时，说明这两次的访问链条将不同方向，不满足题目要求，break排除；
7. 当 visit[next] == start时，说明本次遍历和本访问链条已经访问过的点相撞，形成了环，满足题目要求，返回 true；
8. 当 visit[next] > 0时，说明撞到了别的访问链条上，无法再形成环，直接break排除；
9. 如果 break之后，就重新寻找下一个未访问过的点，作为start，遍历新的链条。
### 代码

```c
/* *************************************************** **
** 1. visit 数组，用于标记相应的数据已经被访问，默认值为 -1，表示未被访问，访问后填充start值；
** 2. start , cur , next 三个变量索引数组，start表示某次遍历的起点,cur表示遍历的当前点，next是将要遍历的下一个点；
** 3. 所有被cur访问的点，都用start值填充visit，也就是visit[cur] = start; 表示该点被以start为起点的访问链条访问过；
** 4. next由cur + nums[cur]进行两次 +size 取模运算，排除负数的情况；
** 5. 当 next == cur时，说明该点下一个要访问的是自己，不满足长度 >1 的要求，所以 break排除；
** 6. 当 nums[next] * nums[cur] < 0 时，说明这两次的访问链条将不同方向，不满足题目要求，break排除；
** 7. 当 visit[next] == start时，说明本次遍历和本访问链条已经访问过的点相撞，形成了环，满足题目要求，返回 true；
** 8. 当 visit[next] > 0时，说明撞到了别的访问链条上，无法再形成环，直接break排除；
** 9. 如果 break之后，就重新寻找下一个未访问过的点，作为start，遍历新的链条。
** *************************************************** */

bool circularArrayLoop(int* nums, int numsSize){
    if(nums == NULL || numsSize<2) return false;
    const int DEBUG = 0;

    int start = 0, next = 0, cur = 0;

    int *visit = (int *)malloc(sizeof(int) * (numsSize + 2));
    for(int i=0; i<numsSize + 1; i++) visit[i] = -1;

    visit[start] = start;
    while(start < numsSize){
        cur = start;
        visit[start] = start;

        while(true){
            next = cur + nums[cur];
            next = ((next%numsSize) + numsSize)%numsSize;

            if(DEBUG) printf("<%s,%d>"\
                "start = %d, cur = %d, next = %d, "\
                "nums[%d] = %d, nums[%d] = %d, "\
                "visit[%d] = %d\n",
                __FUNCTION__,__LINE__,
                start,cur,next,
                cur,nums[cur],next,nums[next],
                next,visit[next]);

            if((visit[next]>0 && visit[next] != start)|| next == cur || nums[cur] * nums[next] < 0)break;
            if(visit[next] == start) return true;

            cur = next;
            visit[cur] = start;
        }
        while(visit[++start] >= 0);
    }

    return false;
}


```