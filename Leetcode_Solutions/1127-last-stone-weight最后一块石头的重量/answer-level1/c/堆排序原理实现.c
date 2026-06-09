### 解题思路
1.通过堆排序的原理实现获取最大的两个数
2.仅需要构造堆的那一步，第二部排序不需要（可对 2，3元素排序，方遍取数）
3.每进行一次比较，需要对数据进行重新排序。

### 代码

```c
int lastStoneWeight(int* stones, int stonesSize){
    if(stonesSize == 1)
        return stones[0];
    else if(stonesSize == 0)
        return 0;

    heapify(stones, 0, stonesSize);
    int start;
    while(true){

        if(stones[0] == stones[1]){
            stonesSize = stonesSize - 2;
            start = 2;
        }else{
            stones[1] = stones[0] - stones[1];
            stonesSize = stonesSize - 1;
            start = 1;
        }
        if(stonesSize == 0)
            return 0;
        else if(stonesSize == 1){
           return stones[start];
        }
        heapify(stones, start, stonesSize);
    }

}

-- 构造堆
void heapify(int *stones, int start, int total){
    int fatherIndex, curIndex, temp;
    for(int i = 0; i < total; i++){
        if(start != 0)
            stones[i] = stones[i + start];
        curIndex = i;
        fatherIndex = (i - 1) / 2;
        while(stones[curIndex] > stones[fatherIndex]){
            temp = stones[curIndex];
            stones[curIndex] = stones[fatherIndex];
            stones[fatherIndex] = temp;
            curIndex = fatherIndex;
            fatherIndex = (curIndex - 1) / 2;
        }
    }
   //对二三元素进行排序
	if (total >= 3 && stones[1] < stones[2]) {
		temp = stones[2];
		stones[2] = stones[1];
		stones[1] = temp;

	}
}



```