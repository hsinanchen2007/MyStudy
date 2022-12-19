/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

#if 0 //自己想的土土的方法 歪门邪道
int comp_inc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
 
int comp_dec(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int search_for_node_index(struct ListNode* head, int g_val, int *index)
{
    int i, valid_flag;
    struct ListNode* tmp = NULL;
    
    if (head == NULL || index ==NULL) {
        return -1;
    }
    
    i = 0;
    valid_flag = 0;
    *index = -1;
    for (tmp = head; tmp != NULL; tmp = tmp->next) {
        if (tmp->val == g_val) {
            valid_flag = 1;
            break;
        }
        i++;    
    }
    if (valid_flag == 1) {
        *index = i;
    }
    
    return 0;
}

int numComponents(struct ListNode* head, int* G, int GSize)
{
    int i, j, valid_len;
    int *tmp_array;
    int ret;
    int index;
    int num;
    
    tmp_array = (int *)malloc(sizeof(int) * GSize);
    if (tmp_array == NULL) {
        return -1;
    }
    memset(tmp_array, 0, sizeof(int) * GSize);

    
    valid_len = 0;
    j = 0;
    for (i = 0; i < GSize; i++) {
        index = 0;
        ret = search_for_node_index(head, G[i], &index);
        if (ret != 0) {
            return -1;
        }
        if (index != -1) {
            tmp_array[j++] = index;
            valid_len++;
        }
    }
    
    if (valid_len == 0) {
        return 0;
    }
    /* 先对新数组进行排序 */
    num = 1;
    qsort(tmp_array, valid_len, sizeof(tmp_array[0]), comp_inc);
    for(i = 0; i < valid_len; i ++) {
        if (i == 0) {
            continue;
        } 
        if ((tmp_array[i] - tmp_array[i - 1] != 1) && (tmp_array[i] - tmp_array[i - 1] != 0)) {
            num++;
        }
	}
    
    return num;
}
#else  //正道方法
#define N 10001
int numComponents(struct ListNode* head, int* G, int GSize)
{
    int i;
    int hash_set[N] = {0};
    struct ListNode* tmp = NULL;
    int num;
    int is_consecu;
    
    for (i = 0; i < GSize; i++) {
        hash_set[G[i]] = 1;
        //printf("hash_set[%d] is 1\n", G[i]);
    }
    
    num = 0;
    is_consecu = 0;
    for (tmp = head; tmp != NULL; tmp = tmp->next) {
        //printf("val:%d is_consecu:%d num:%d\n", tmp->val, is_consecu, num);
        if (hash_set[tmp->val] == 1 && is_consecu == 0 && tmp->next != NULL) {
            //printf("1 val:%d is_consecu:%d\n", tmp->val, is_consecu);
            is_consecu = 1;
        } else if (hash_set[tmp->val] == 1 && tmp->next == NULL) {
            //printf("2 val:%d is_consecu:%d\n", tmp->val, is_consecu);
            num++;
        } else if (hash_set[tmp->val] != 1 && is_consecu == 1) {
            //printf("3 val:%d is_consecu:%d\n", tmp->val, is_consecu);
            is_consecu = 0;
            num++;
        }
    }
    
    return num;
}
#endif