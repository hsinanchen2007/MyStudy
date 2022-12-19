思路：从下往上找，比如给的用例中，第三行和第四行
 6，5，7
4，1，8，3
4和1分别加6为10和7，所以7最小，1和8分别加5为6和13,6最小……
所以更新第三行为7，6,10。一直往上更新结果，最后第一行的值就是输出的最小结果。
```
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int row, col;
    
    triangleColSize = (int *)malloc(triangleSize * sizeof(int));
    for (row = triangleSize - 1; row > 0; row--) {
        triangleColSize[row] = row + 1;
        for (col = 0; col <= row - 1; col++) {
            triangle[row - 1][col] += (triangle[row][col] < triangle[row][col + 1]) ? triangle[row][col] : triangle[row][col + 1];
        }
    }   
    return triangle[0][0];
}

```
