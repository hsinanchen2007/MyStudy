### 解题思路
此处撰写解题思路

### 代码

```c
//直接qsort排序，在1000000000的用例时会超时，才用hash存一下
struct hash_entry {
    int key;
    int num;
    UT_hash_handle hh;

};

struct hash_entry *g_this;
int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    int num = 0;

    if(n <= 0 || reservedSeats == NULL || reservedSeatsSize <= 0) {
        return 0;
    }
    num = 2 * n;
    for (int i = 0; i < reservedSeatsSize; i++) {
        struct hash_entry *temp;

        int layer = reservedSeats[i][0];
        HASH_FIND_INT(g_this, &layer, temp);
        if (temp == NULL) {
            temp = (struct hash_entry *)malloc(sizeof(struct hash_entry));
            temp->key = layer;
            temp->num = 0;
            temp->num |= 1 << (reservedSeats[i][1] - 1);
            HASH_ADD_INT(g_this, key, temp);
        } else {
            temp->num |= 1 << (reservedSeats[i][1]- 1);
        }

    }
    struct hash_entry *temp;

    int l = 0b0000011110;//左边安排时 0000011110       注意低位在右
    int r = 0b0111100000;//右边安排时 0111100000
    int mid1 = 0b0001111000;//中间安排一个时0001111000
    int mid2 = 0b0111111110;//中间安排两个时 0111111110

    for (temp = g_this; temp != NULL; temp = (struct hash_entry *)temp->hh.next) {
        num = num - 2;
        //printf("temp->num = %d\n", temp->num);
        if ((mid2 & temp->num) == 0 ) {
            //printf("mid2\n");
            num = num +2;
        } else if ((mid1 & temp->num) == 0  || (l & temp->num) == 0 || (r & temp->num) == 0 ) {
            //printf("mid1\n");
            num++;
        }
        HASH_DEL(g_this, temp);
    }

    return num;
}







```