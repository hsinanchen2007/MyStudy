### 解题思路
本题解效率不是最高，但思路非常清晰。

首先分析题意，需要按列比较：
1.如果一列都按字典序且无相等，则成功返回；

2.如果一列按字典序且有相等，则相等位置要传递到下一列比较；

3.如果一列不满足字典序，则本列删除，需要比较的位置在下一列继续比较。

具体实现步骤：

1.设立两个标志数组：cur和nxt，cur初始化为0，表示都需要比较

2.判断一列每个位置，根据cur数组，如果：
    a.cur[i]为1，则nxt[i]=1，即将无需比较的状态进行传递
    b.cur[i]为0，则需要比较,有满足字典序且无相等nxt[i] = 1；有相等nxt[i] = 0；不满足则退出
3.如果遍历完一列，无相等无不满足，则成功返回；

4,如果遍历完一列，有相等，则将nxt变为cur继续下一列比较

5.如果遍历完一列，需要删除，则继续使用cur进行下一列比较

![image.png](https://pic.leetcode-cn.com/8ca2e20a5ac850511d931d3b12a5ccff7a14c25ad95d2eae7af61af32082e1a5-image.png)



### 代码

```c
/*
 * @lc app=leetcode.cn id=955 lang=c
 *
 * [955] 删列造序 II
 */

// @lc code=start

//【算法思路】贪心。
//1.从第一列开始判断，初始化flags[0:n] = 0
//3.遍历列j，如果flags[j] = 0，则进行：
//4.如果A[i][j] > A[i][j + 1] 本次判断结束;
//4.如果A[i][j] == A[i][j + 1] 则在flag[j] = 0;
//4.如果A[i][j] < A[i][j + 1] 则在flag[j] = 1;
//5.如果统计完成，没有出现相等，结束
//6.如果出现相等，继续判断下一列
int minDeletionSize(char ** A, int ASize){
    int *cur_ = (int *)calloc(ASize, sizeof(int));
    int *nxt_ = (int *)calloc(ASize, sizeof(int));

    int *cur = cur_;
    int *nxt = nxt_;

    int slen = strlen(A[0]);
    int ret = 0;

    for(int i = 0; i < slen; i++) {
        bool is_delete = false;
        bool is_equal = false;
        
        for(int j = 0; j < ASize - 1; j++) {
            if(cur[j] == 1) {
                //已经无需判断，则传递状态
                nxt[j] = 1;
                continue;
            }

            if(A[j][i] < A[j + 1][i]) {
                //无需下次判断，设置状态
                nxt[j] = 1;
            } else if(A[j][i] > A[j + 1][i]){
                //比较失败，本列需要删除，先设置标志
                is_delete = true;
                break;
            } else {
                //相等则需要下次判断，设置状态和标志
                nxt[j] = 0;
                is_equal = true;
            }
        }
/*
        printf("is_delete = %d, is_equal = %d\n", is_delete, is_equal);
        for(int j = 0; j < ASize; j++) {
            printf("[%d]%d    ", j, cur[j]);
        }
        printf("\n");
*/
        if(is_delete) {
            //当前行删除，使用相同cur继续标志判断下一列
            ret++;
        } else if(is_equal) {
            //有相等情况，需要使用新的标志，判断下一列
            int *tmp= cur;
            cur = nxt;
            nxt = tmp;
        } else {
            //无需删除且无相等情况，已经满足要求
            break;
        }
    }
    //如果仍有相等，则各个单词相等，可以满足要求

    return ret;
}


// @lc code=end


```