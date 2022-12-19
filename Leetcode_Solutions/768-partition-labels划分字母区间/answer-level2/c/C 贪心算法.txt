### 解题思路
思路简单，重点在于细节

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * S, int* returnSize){
    //////记录每个不同的字符出现的第一个和最后一个位置--二维数组
    int **letterPosition = (int **)malloc(26 * sizeof(int *));//26个英文字母
    letterPosition[0] = (int *)malloc(2 * sizeof(int));
    letterPosition[0][0] = 0;//初始化，把第一个放进去
    letterPosition[0][1] = 0;
    int letterIdx = 0;//记录字母个数（下标）

    int i = 0, j = 1;
    int flag = 0;
    int k;
    while(S[i+1]){
        i++;
        for(k = 0;k<=letterIdx;k++){
            if(S[i] == S[letterPosition[k][0]]){   
                letterPosition[k][1] = i; //遍历已有字母列表，已经存在该字母时，更新最大位置下标
                flag = 1;//字母存在的标记
                break;
            }
            flag = 0;//字母不存在时，是新字母标记
        }
        if(!flag){
            letterIdx++;
            letterPosition[letterIdx] = (int *)malloc(2 * sizeof(int));//分配新空间
            letterPosition[letterIdx][0] = i;
            letterPosition[letterIdx][1] = i;
            flag = 0;//保持flag
        }
    }
    int *res = (int *)malloc((letterIdx + 1) * sizeof(int));

    //////处理重叠区间
    int start, last;
    int zoneNum = 0;//记录区间个数下标
    int lap = 0;
    for(i = 0; i <= letterIdx; i++){
        start = letterPosition[i][0];//新区间的起始字母
        last = letterPosition[i][1];

        for(j = i + 1; j <= letterIdx; j++){
            if(last > letterPosition[j][0]){
                lap++;//记录重叠区间数，以推进i和j的更新      
                last = last > letterPosition[j][1] ? last : letterPosition[j][1];//更新最大位置下标               
            }
            else{
                break;//一旦找不到，即区间断开，结束循环
            }
        }
        
        res[zoneNum++] = last - start + 1;
        if(letterPosition[j-1][1] == strlen(S) - 1) break;//存在某个区间的右边界到达了字符串末尾，不必再继续比较了
        i = i + lap;//更新i
        lap = 0;
    }
    *returnSize = zoneNum;//注意下标与元素个数的区别
    return res;

}
```