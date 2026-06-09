### 解题思路
# 我看到这一题的想法：
“这一题用了双指针，不会呀！第一次见也是前几天做的“腐坏的橘子”（一道题）”。不知道有多少人和我一样，没怎末接触过这样的题型。“去看看别人写的吧！”然后我就看了力扣上其他人的代码。“这思路和我的一样啊，我去咋还需要给这两个指针赋值啊！还要传回去不成？” 我蒙了 “咋还又定义了一个指针，不能用系统给的吗？” 大概看了10多分钟吧，清楚了题目中给的变量是干啥的了，也大概明白了要怎样写这样的题。


# 写完并提交后我的看法
先看题目，首先核心要求是：用连续的数字并且小于给定的数来表示给定的**target**，其次便是从小到大，这也是自然而然，毕竟是简单题没必要折磨麻烦。给的限制说的是**1 <= target <= 10^5**，应该是想说明数不大，可以用暴力法，但毕竟还没写不能确定（事实证明可以）。

然后就是难到了我和一大帮人的函数定义了，我先解释下**returnSize**，也就是第一个指针变量，它所起到的作用是向主程序传递所返回的二维数组一共有多少“行”，而**returnColumnSizes**则是返回每一行所包含的数字个数。这应该是绝大多数人所困惑的地方。然后来说说怎样判断这两个变量的含义，开始我以为是因为自己英语差的原因，无法**get**到这两个**point**，后来我从专业的角度想:returnSize是一个指向整形变量的指针，那么它所改变的一定是主程序中的一个整形变量，而returnColumnSizes是一个指向指针的指针变量，那么它所改变的就有可能是一个数组。之所以从这两个变量中选择，是因为只有行数和行数中的总个数可以确定一个二维数组。
其他的思路地方的问题，我都用注释的方式说明了。

  ```c

```
**以上就是我的文章，觉得有帮助有价值的话，希望能点个赞，关注和转发。**



### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **findContinuousSequence(int target, int *returnSize, int **returnColumnSizes)
{
    int end = target / 2;
    int *array = (int *)malloc(sizeof(int) * end);
    int **Output = (int **)malloc(sizeof(int *) * end);
    int sum = 0, col_count = 0, col_nums = 0; //count是每一行有多少元素  nums是有多少行
    for (int i = 1; i <= end; i++)
    {
        sum=0;
        col_count = 0; //每一行有多少个元素
        int j = i;  //j是为了知道结束的位置
        while (sum < target)
        {
            col_count++;
            sum += j;
            j++; //j多加了一次，所以下面<j
        }
        if (sum == target)
        {
            Output[col_nums] = (int *)malloc(sizeof(int) * (col_count));
            array[col_nums] = col_count;
            for (int n = i; n < j; n++)
                Output[col_nums][n - i] = n;
            //给二维数组赋值
            col_nums++;
        }
    }
    *returnSize = col_nums;
    *returnColumnSizes = array;
    return Output;
}
```