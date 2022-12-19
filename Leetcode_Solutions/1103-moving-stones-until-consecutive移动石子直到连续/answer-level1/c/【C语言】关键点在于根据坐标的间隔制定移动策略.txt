
示例1有误导性，其实还可以将a处的石子移动到3，再把c处的石子移动到4；或者把a处的石子移动到4，再把b处的石子移动到3

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 将三个坐标按升序排序，假设排序后的坐标为x,y,z，目标是然后把x和z都移动到y两侧，形成三个连续的整数
// 求出三个坐标之间的整数个数 delta1=y-x-1 和 delta2=z-y-1
// 由于a,b,c各不相等，因此delta1 和 delta2不小于0
// 1.最大移动次数的情况，对应于以1为步伐，将x和z逐步移动到y两侧，移动次数为 delta1 + delta2 
// 2.最小移动次数的情况：移动1次走尽可能多步。求出delta1和delta2中的较小者delta_min，将处于该区间外侧的坐标移动到区间内（即中间坐标的两侧），然后再把delta_min另一个端点的坐标移动到中间坐标的另一侧
// 2.1 如果三个坐标紧紧挨着，那么移动次数为0；
// 2.2 如果某个端点坐标处于y的旁边，那么就把另一个端点坐标移动到y的另一侧，移动次数为1
// 2.3 如果某个端点坐标与y之间只有1个空位，那么就把另一个端点坐标移动到这个空位，移动次数为1
// 2.4 其他情况，只需要将一个端点坐标一步移动到y的一侧，把另一个端点坐标一步移动到y的另一侧，移动次数为2
// 在返回数组answer中，answer[0]表示最小移动次数，answer[1]表示最大移动次数


```
#include <stdlib.h>
#include <string.h>

// 按照升序排列
int compare(const void* a, const void* b) 
{
    return *(int*)a > *(int*)b;  // 用比较取代减法，防止溢出
}

int* numMovesStones(int a, int b, int c, int* returnSize)
{
    int* answer = (int*)malloc(2 * sizeof(int));
    memset(answer, 0, 2 * sizeof(int));

    int nums[3] = {a, b, c}; // 把三个坐标放进数组nums
    qsort(nums, 3, sizeof(int), compare);//最小坐标为nums[0]，中间坐标为nums[1], 最大坐标为nums[2]
    int delta1 = nums[1] - nums[0] - 1;  // delta1>=0
    int delta2 = nums[2] - nums[1] - 1;  // delta2>=0

    if (delta1 == 0 && delta2 == 0) {
        answer[0] = 0;
    } else if (delta1 == 0 || delta2 == 0) {
        answer[0] = 1;
    } else if (delta1 == 1 || delta2 == 1) {
        answer[0] = 1;
    } else {
        answer[0] = 2;
    }

    answer[1] = delta1 + delta2;

    *returnSize = 2;

    return answer;
}
```