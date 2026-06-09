### 解题思路
本题是参考其他人的解法完成的，这里给出C语言的实现。

1.构建线段树

2.构建用于查找结果的id映射

3.在线段树中查询一段区间

4.获得该区间最有可能的数值val

5.从id映射中二分查找落在查询区间的val个数

其中考察了线段树，uthash，和二分的知识点。

![image.png](https://pic.leetcode-cn.com/e117fc9c856839f7073999d23c8d12a57973d0f95fb00614e3295c5bf98e6c1f-image.png)


### 代码

```c
#define IDS_MAX     20000

typedef struct _info_st {
    int val;
    int cnt;
}info_st;

typedef struct _node_st {
    //base
    int start;
    int end;
    //service
    info_st info;
    //link
    struct _node_st *left;
    struct _node_st *right;
}node_st;

typedef struct _hash_st {
    int key;
    int ids[IDS_MAX];
    int icnt;
    UT_hash_handle hh;
}hash_st;

typedef struct {
    node_st *root;
    hash_st *head;
    hash_st *pool;
} MajorityChecker;

node_st *build(int *arr, int arrSize, int start, int end) {
    node_st *new = (node_st *)calloc(1, sizeof(node_st));
    new->start = start;
    new->end = end;

    if(start == end) {
        new->info.val = arr[start];
        new->info.cnt = 1;
        goto DONE;
    }

    int mid = (start + end) / 2;

    new->left = build(arr, arrSize, start, mid);
    new->right = build(arr, arrSize, mid + 1, end);

    if(new->left->info.val == new->right->info.val) {
        new->info.val = new->left->info.val;
        new->info.cnt = new->left->info.cnt + new->right->info.cnt;
    } else {
        new->info.val = (new->left->info.cnt > new->right->info.cnt)? new->left->info.val : new->right->info.val;
        new->info.cnt = abs(new->left->info.cnt - new->right->info.cnt);
    }

    //printf("start = %d, end = %d, val = %d, cnt = %d\n", start, end, new->info.val, new->info.cnt);
DONE:
    return new;
}

void query(node_st *root, int left, int right, info_st *info) {
    int start = root->start;
    int end = root->end;

    if(right < start || left > end) {
        //区间不相关
        info->val = 0;
        info->cnt = 0;
        return;
    } else if(left <= start && right >= end) {
        info->val = root->info.val;
        info->cnt = root->info.cnt;
        return;
    }

    info_st linfo, rinfo;

    query(root->left, left, right, &linfo);
    query(root->right, left, right, &rinfo);

    if(linfo.val == rinfo.val) {
        info->val = linfo.val;
        info->cnt = linfo.cnt + rinfo.cnt;
    } else {
        info->val = (linfo.cnt > rinfo.cnt)? linfo.val : rinfo.val;
        info->cnt = abs(linfo.cnt - rinfo.cnt);
    }

    return;
}

void delete(node_st *root) {
    if(root->start == root->end) {
        free(root);
        return;
    }

    delete(root->left);
    delete(root->right);

    free(root);
}

//【算法思路】线段树+hash+二分。
//信息存储：最有可能的过半数的val和cnt
//        (1)如果两个子区间val相同，则根区间为val和cnt之和
//        (2)如果两个子区间val不同，则跟区间val为数量多的，个数为多数减少数的cnt
//线段树找到待查询数据后，使用hash记录数据索引，使用二分法找到该数据使用的次数
MajorityChecker* majorityCheckerCreate(int* arr, int arrSize) {
    MajorityChecker *obj = (MajorityChecker *)calloc(1, sizeof(MajorityChecker));
    obj->root = build(arr, arrSize, 0, arrSize - 1);
    hash_st *pool = (hash_st *)calloc(arrSize, sizeof(hash_st));
    int psize = 0;

    hash_st *head = NULL;
    for(int i = 0; i < arrSize; i++) {
        //先查询是否添加了该值
        hash_st *tmph;
        HASH_FIND(hh, head, &arr[i], sizeof(int), tmph);
        if(tmph == NULL) {
            hash_st *new = &pool[psize++];
            new->key = arr[i];
            new->ids[0] = i;
            new->icnt = 1;

            HASH_ADD_KEYPTR(hh, head, &(new->key), sizeof(int), new);
        } else {
            tmph->ids[tmph->icnt++] = i;
        }   
    }

    obj->head = head;
    obj->pool = pool;

    return obj;
}

int majorityCheckerQuery(MajorityChecker* obj, int left, int right, int threshold) {
    info_st info;
    query(obj->root, left, right, &info);

    //printf("query: left = %d, right = %d, thres =%d, val = %d, cnt = %d\n", left, right, threshold, info.val, info.cnt);

    if(info.cnt == 0) {
        return -1;
    }

    //从hash表中找到对应的值，及其id表
    hash_st *tmph;
    HASH_FIND(hh, obj->head, &(info.val), sizeof(int), tmph);
    
    int *ids = tmph->ids;
    int icnt = tmph->icnt;
/*
    for(int i = 0; i < icnt; i++) {
        printf("%d  ", ids[i]);
    }
    printf("\n");
*/
    //二分查找左右边界
    int ret;
    if(ids[0] >= left && ids[icnt - 1] <= right) {
        ret = icnt;
        goto DONE;
    } else if(ids[0] > right || ids[icnt - 1] < left) {
        ret = -1;
        goto DONE;
    } else if(ids[0] == right || ids[icnt - 1] == left) {
        ret = 1;
        goto DONE;
    }
    //此时right一定大于ids[0],left一定小于ids[icnt - 1]
    int tl, tr;

    //先找左边界
    int tar = left;
    int ll = 0, rr = icnt - 1;

    while(ll < rr) {
        int mid = (ll + rr) / 2;

        if(ids[mid] > tar) {
            rr = mid;
        } else {
            ll = mid + 1;
        }
    }
    
    tl = ll;

    //再找右边界
    tar = right;
    ll = 0, rr = icnt - 1;

    while(ll < rr) {
        int mid = (ll + rr) / 2;

        if(ids[mid] > tar) {
            rr = mid;
        } else {
            ll = mid + 1;
        }
    }

    tr = ll;

    //printf("tl = %d, tr = %d\n", tl, tr);

    if(left <= ids[0]) {
        ret = tr;              //当left小于等于左边界
    } else if(right >= ids[icnt - 1]) {
        ret =  icnt - tl + 1;   //当right大于等于右边界
    } else {
        ret =  tr - tl;     //都位于内部
        if(tl > 0 && ids[tl - 1] == left) {
            ret++;
        }
    }
DONE:
    return ret >= threshold? info.val : -1;
}

void majorityCheckerFree(MajorityChecker* obj) {
    //正常释放，会超时
    //delete(obj->root);
    //free(obj->pool);
    free(obj);
}

/**
 * Your MajorityChecker struct will be instantiated and called as such:
 * MajorityChecker* obj = majorityCheckerCreate(arr, arrSize);
 * int param_1 = majorityCheckerQuery(obj, left, right, threshold);
 
 * majorityCheckerFree(obj);
*/
```