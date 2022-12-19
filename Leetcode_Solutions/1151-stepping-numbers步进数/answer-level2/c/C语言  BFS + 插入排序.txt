看代码注释吧

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//全局变量
int* result;
int gIndex;

//插入排序，够用
void sort(int* arr, int len){
    for(int i = 0; i<len; i++){
        for(int j = i; j< len; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/*bfs，结果是无序的。 比如0-1000的范围内，从一个值4开始，得搜出来
  4 43 432 
       433
    45 454
       456
*/
void dfs(int low, int high, long value, int lastBit){
    if(value >= low && value <= high){
        result[gIndex] = value;
        gIndex++;
    }else if(value > high){ //超出就退出，深搜到底端了
        return;
    }

    if(lastBit == 0){
        dfs(low,high,value*10 + lastBit + 1,lastBit + 1);
    } else if(lastBit == 9){
        dfs(low,high,value*10 + lastBit - 1,lastBit - 1);
    } else {
        dfs(low,high,value*10 + lastBit - 1,lastBit - 1);
        dfs(low,high,value*10 + lastBit + 1,lastBit + 1);
    }

}

int* countSteppingNumbers(int low, int high, int* returnSize){
    result = (int*)malloc(sizeof(int) * 10000);
    gIndex = 0;

    //0单独处理
    if(0 >= low && 0 <= high){
        result[gIndex] = 0;
        gIndex++;
    }
    //1 - 9 开始深搜
    for(int i = 1; i <=9; i++){
        dfs(low,high,i,i);
    }
    *returnSize = gIndex;
    sort(result,gIndex);
    return result;
}

```
