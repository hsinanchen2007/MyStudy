### 解题思路
这道题，思路不难，总的来说，就是先用礼包，然后再用单购；
剪枝条件：
1、如果礼包本身重复购买后已经无法满足条件的话，后续选择就不应该再选择了；而且如果pack1永远不能出现再pack2之后，那样子就会有重复。
2、如果有1个礼物的数量超标则当前递归停止；
3、如果当前的花销已经超过最小花销，则递归停止；

### 代码

```c
void dfs(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* needs, int needsSize, int *offersNum, int curCost, int *minCost, int startIndex)
{
    /* 结束条件: 数量全部匹配 */
    int endFlag = 1;
    for (int i = 0; i < needsSize; i++) {
        if (offersNum[i] < needs[i]) {
            endFlag = 0;
            break;
        }
    }
    if (endFlag) {
        if (curCost < *minCost) {
            *minCost = curCost;
        }
        return;
    }
    /* 遍历全部选择列表 */
    for (int i = startIndex; i < specialSize + priceSize; i++) {
        if (i < specialSize) {
            /* 选取礼包 */
            int isCntMatch = 1;
            for (int j = 0; j < needsSize; j++) {
                offersNum[j] += special[i][j];
            }
            curCost += special[i][specialColSize[i] - 1];            
            for (int j = 0; j < needsSize; j++) {
                if (offersNum[j] > needs[j]) {
                    isCntMatch = 0;
                    break;
                }
            }
            if (isCntMatch && curCost < *minCost) {
                if (startIndex != i) {
                    startIndex = i;
                }
                dfs(price, priceSize, special, specialSize, specialColSize, needs, needsSize, offersNum, curCost, minCost, startIndex);
            }
            /* 恢复选择 */
            curCost -= special[i][specialColSize[i] - 1];   
            for (int j = 0; j < needsSize; j++) {
                offersNum[j] -= special[i][j];
            }                     
        } else {
            int k = i - specialSize;
            offersNum[k]++;
            curCost += price[k];
            if (offersNum[k] <= needs[k] && curCost < *minCost) {
                if (startIndex != i) {
                    startIndex = i;
                }                
                dfs(price, priceSize, special, specialSize, specialColSize, needs, needsSize, offersNum, curCost, minCost, startIndex);
            }
            curCost -= price[k];            
            offersNum[k]--;            
        }
    }
    return;
}

int shoppingOffers(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* needs, int needsSize)
{
    if (price == NULL || special == NULL || specialColSize == NULL || needs == NULL) {
        return 0;
    }
    if (priceSize == 0 || specialSize == 0 || needsSize == 0) {
        return 0;
    }
    int *offersNum = (int *)malloc(needsSize * sizeof(int));
    memset(offersNum, 0, needsSize * sizeof(int));
    int minCost = 100000;
    int curCost = 0;
    dfs(price, priceSize, special, specialSize, specialColSize, needs, needsSize, offersNum, curCost, &minCost, 0);
    return minCost;
}
```