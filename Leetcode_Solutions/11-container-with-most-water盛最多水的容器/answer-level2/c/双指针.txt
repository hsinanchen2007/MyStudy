### 解题思路
此处撰写解题思路

### 代码

```c

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
int maxArea(int* height, int heightSize){
    int i,j = 0;
    int maxA = 0;
    int AreaTemp = 0;
 
   i = 0;
   j = heightSize - 1;
   while (i < j) {
        AreaTemp = MIN(height[i], height[j]) * (j - i);
        maxA = MAX(maxA, AreaTemp);
        if  (height[i] < height[j])  {
             i++;
        } else {
             j--;
        }
   }
   return maxA;
}
```