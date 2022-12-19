### 解题思路
此处撰写解题思路

### 代码

```c
struct hash_entry {
    int num;
    int count;
    UT_hash_handle hh;
};

struct hash_entry *g_head;

bool isHappy(int n)
{
    if (n == 1) {
        return true;
    }
    int flag = 0;
    while (1) {
        struct hash_entry *temp;
        if (n == 1) {
            flag = 0;
            break;
        }
        HASH_FIND_INT(g_head, &n, temp);
        if (temp == NULL) {
            temp = (struct hash_entry *)malloc(sizeof(struct hash_entry));
            temp->num = n;
            temp->count = 1;
            HASH_ADD_INT(g_head, num, temp);

        } else {
            flag = 1;
            break;
        }
        int sum = 0;
        while(n != 0) {
            int temp = n % 10;
            n = n / 10;
            sum = sum + temp *temp; 
        }
        n = sum;
    }
    struct hash_entry *temp;
    for (temp = g_head; temp != NULL; temp = (struct hash_entry *)temp->hh.next) {
        HASH_DEL(g_head, temp);
    }


    if (flag == 0) {
        return true;
    }
    return false;
}
```