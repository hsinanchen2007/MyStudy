### 解题思路
保存sum,get时递归获取

### 代码

```c
#define MAX_SUM_NUM 200
typedef struct{
   int val;
   int flag;
   int countIndex;
   int sumRow[MAX_SUM_NUM];
   int sunCol[MAX_SUM_NUM];
}SumExcel;

typedef struct {
    int row;
    int col;
    SumExcel **value;
} Excel;


Excel* excelCreate(int H, char W) {
    Excel *tmpExcel = NULL;

    tmpExcel = (Excel *)malloc(sizeof(Excel));
    tmpExcel->row = H;
    tmpExcel->col = W -'A' + 1;
    tmpExcel->value = (SumExcel **)malloc(sizeof(SumExcel *) * H);
    for (int i = 0 ; i < H; i++) {
        tmpExcel->value[i] = (SumExcel *)malloc(sizeof(SumExcel) * (tmpExcel->col));
        memset(tmpExcel->value[i], 0, sizeof(SumExcel) * (tmpExcel->col));
    }
    return tmpExcel;
}

void excelSet(Excel* obj, int r, char c, int v) {

    int tmpRow = r -1;
    int tmpCol = c - 'A';
    obj->value[tmpRow][tmpCol].flag = 0;
    obj->value[tmpRow][tmpCol].countIndex = 0;
    obj->value[tmpRow][tmpCol].val = v;
    return;
  
}

int excelGet(Excel* obj, int r, char c) {
    int tmpRow = r -1;
    int tmpCol = c - 'A';
    int tmpSum = 0;
    int sumRow = 0;
    int sumCol = 0;

    if (obj->value[tmpRow][tmpCol].flag == 0) {
         return obj->value[tmpRow][tmpCol].val;
    }
    
    for (int i = 0; i < obj->value[tmpRow][tmpCol].countIndex; i++) {
        sumRow = obj->value[tmpRow][tmpCol].sumRow[i];
        sumCol = obj->value[tmpRow][tmpCol].sunCol[i];
        tmpSum += excelGet(obj, sumRow + 1, 'A' + sumCol);
    }

    return tmpSum;
}

int excelSum(Excel* obj, int r, char c, char ** strs, int strsSize) {
  char* tmpchar;
  int tmpRow = r -1;
  int tmpCol = c - 'A';
  int tmpIndex = 0;
  char tmpstr[4] = {0};
  int tmpSum = 0;

  if (obj->value[tmpRow][tmpCol].flag == 1) {
      obj->value[tmpRow][tmpCol].countIndex = 0;
  }
  obj->value[tmpRow][tmpCol].flag = 1;
  for (int i = 0; i < strsSize; i++) {
      tmpchar = strchr(strs[i], ':');
      if (tmpchar == NULL) {
          tmpIndex = obj->value[tmpRow][tmpCol].countIndex;
          obj->value[tmpRow][tmpCol].sumRow[tmpIndex] = (atoi(strs[i] + 1) - 1);
          obj->value[tmpRow][tmpCol].sunCol[tmpIndex] = strs[i][0] - 'A';
          obj->value[tmpRow][tmpCol].countIndex++;
      } else {
          int start = 0;
          int end = 0;
          strncpy(tmpstr, strs[i], tmpchar - strs[i]);
          start = atoi(tmpstr + 1);
          end = atoi(tmpchar + 2);
          for (int j = start - 1; j <= end - 1; j++) {
              for(int k = (tmpstr[0] - 'A'); k <= (*(tmpchar + 1) - 'A'); k++) {
                    tmpIndex = obj->value[tmpRow][tmpCol].countIndex;
                    obj->value[tmpRow][tmpCol].sumRow[tmpIndex] = j;
                    obj->value[tmpRow][tmpCol].sunCol[tmpIndex] = k;
                    obj->value[tmpRow][tmpCol].countIndex++;
              }
          }
      }
  }
  tmpSum = excelGet(obj, r, c);
  return tmpSum;
}

void excelFree(Excel* obj) {
    for (int i = 0; i < obj->row; i++) {
        free(obj->value[i]);
    }
    free(obj->value);
    free(obj);
    return;
}

/**
 * Your Excel struct will be instantiated and called as such:
 * Excel* obj = excelCreate(H, W);
 * excelSet(obj, r, c, v);
 
 * int param_2 = excelGet(obj, r, c);
 
 * int param_3 = excelSum(obj, r, c, strs, strsSize);
 
 * excelFree(obj);
*/
```