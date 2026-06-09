// LeetCode447. 回旋镖的数量
// 给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 
// i 和 k 之间的距离相等（需要考虑元组的顺序）。
// 找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。

// 思路：
// 每个点都是一对二维坐标(xi, yi)
// 最少需要3个点才能形成boomerang
// n对不相同的点(x1, y1), (x2, y2),..., (xn, yn); points是一个n行2列的数组
// xi的范围: [-10000, 10000]
// yi的范围: [-10000, 10000]
// 算法：组合数
// 遍历所有点，以其中一个点i为锚点
// 计算其它点到点i的距离，
// 按距离按升序排序，以遇到不相等距离为界限，统计距离相等的个数p
// 只要从这p个点中任意抽取2个，就能和点i形成Boomerang，因此一共有C(2, n)中抽取方法[组合数]，每种抽取可以形成2个回形标
// 共 p(p-1)个
// 将p(p-1)累计到总数sum
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
// 
**// 统计距离个数有2种方法：
// (1)hashmap,以距离为key，个数为value。【每1个新增的距离相等的点，都能够与原来的a个点进行组合，相当于增加了a*2个回形标。】
// (2)排序+遍历，以遇到不相等距离为界限，统计距离相等的个数**


```
#include <stdlib.h>
#define MAX_N 500

int compare(const void* a, const void* b)
{
	return *(int*)a > *(int*)b;
}

int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize)
{
    if (points == NULL || pointsSize < 3 || pointsSize > 500) {
        return 0;
    }

    int distance[MAX_N] = {0};  // 距离数组
    int sum = 0;
    int i;	// 指针，选择锚点
    int j;	// 指针，计算距离

    for (i = 0; i < pointsSize; i++) {
    	// 计算每一点到点i的距离
    	for (j = 0; j < pointsSize; j++) {	
    		distance[j] = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
    					  (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
    	}

    	// 对距离按升序排序
    	qsort(distance, pointsSize, sizeof(int), compare);

    	int currCount = 1;  // 当前计数
    	
    	// 遍历排序后的距离，统计个数
    	for (j = 1; j < pointsSize; j++) {
    		if (distance[j] != distance[j - 1]) {
    			sum += currCount * (currCount - 1);
    			currCount = 1;
    		} else {
    			currCount++;
    		}
    	}

    	// 记得统计最后一个单词
    	sum += currCount * (currCount - 1);
    }

    return sum;
}
```
