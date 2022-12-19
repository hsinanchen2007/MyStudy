执行用时 :
196 ms
, 在所有 C 提交中击败了
50.53%
的用户
内存消耗 :
16.8 MB
, 在所有 C 提交中击败了
100.00%
的用户

### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int rowid;
    int seatid;
}seat_st;
int CmpSeatInfo(const void *a, const void *b) {
    if (((seat_st *)a)->rowid != ((seat_st *)b)->rowid) {
        return ((seat_st *)a)->rowid - ((seat_st *)b)->rowid;
    } else {
        return ((seat_st *)a)->seatid - ((seat_st *)b)->seatid;
    }
    
}
int GetSeatsInTen(int *arr) {
    if ((arr[2] == 0) && (arr[3] == 0) && (arr[4] == 0) && (arr[5] == 0) &&
    (arr[6] == 0) && (arr[7] == 0) && (arr[8] == 0) && (arr[9] == 0)) {
        return 0;
    }
    if (((arr[2] == 0) && (arr[3] == 0) && (arr[4] == 0) && (arr[5] == 0)) || 
    ((arr[6] == 0) && (arr[7] == 0) && (arr[8] == 0) && (arr[9] == 0)) ||
    ((arr[6] == 0) && (arr[7] == 0) && (arr[4] == 0) && (arr[5] == 0))){
        return 1;
    }
    else {
        return 2;
    }
}
//int GetSeatContinue(int rows, seat_st *seat_info, int *RowNo, int idMax)
int GetSeatContinue(int rows, seat_st *seat_info, int idMax)
{
    int i;
    int j = 0;
    int id = 0;
    int num = 0;
    int arr[11];
    int tmp;
    int RowNo;
    for (i = seat_info[id].rowid; i <= seat_info[idMax - 1].rowid; ) {
        //printf("ok5\n");
        memset(arr,0,sizeof(int) * 11);
        arr[seat_info[id].seatid] = 1;
        RowNo = 1;
        tmp = id + 1;
        while (tmp < idMax && seat_info[id].rowid == seat_info[tmp].rowid) {
            arr[seat_info[tmp].seatid] = 1;
            RowNo++;
            tmp++;
        }
        if (RowNo >= 7) {
            num += 2;
            id = id + RowNo;
            if (id < idMax) {
                i = seat_info[id].rowid;
            } else {
                i++;
            }
            continue;
        }
        if (RowNo == 1) {
            if ((seat_info[id].seatid == 1) || ((seat_info[id].seatid == 10))) {
                num += 0;
            } else {
                num += 1;
            }
            id = id + RowNo;
            if (id < idMax) {
                i = seat_info[id].rowid;
            } else {
                i++;
            }
            continue;
        }
        
        num += GetSeatsInTen(arr);
        id = id + RowNo;
        //printf("ok4\n");
        if (id < idMax) {
            i = seat_info[id].rowid;
        } else {
            i++;
        }
    }
    return rows*2 - num;
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize){
    int i;
    int rowid;
    int num;
    seat_st* seat_info;
    //int *RowNo;
    int rows = n;
    int seatsSize = reservedSeatsSize;
	if (reservedSeatsSize == 0) {
	    return n * 2;
	}
    if ((reservedSeats == NULL) || (n == 0)) {
        return 0;
    }
    seat_info = (seat_st *)malloc(sizeof(seat_st) * reservedSeatsSize);
    //RowNo = (int *)malloc(sizeof(int) * rows);
    //if (RowNo == NULL || seat_info == NULL) {
    //    return 0;
    //}
    //memset(RowNo, 0, sizeof(int) * rows);
    for (i = 0; i < seatsSize; i++) {
        seat_info[i].rowid = reservedSeats[i][0] - 1;
        seat_info[i].seatid = reservedSeats[i][1];
        //RowNo[reservedSeats[i][0] - 1]++;
    }
    //printf("ok1\n");
    qsort(seat_info, seatsSize, sizeof(seat_st), CmpSeatInfo);
    //printf("ok2\n");
    //num = GetSeatContinue(rows, seat_info, RowNo, seatsSize);
    num = GetSeatContinue(rows, seat_info, seatsSize);
    //printf("ok3\n");
    free(seat_info);
    //free(RowNo);
    return num;
}


```