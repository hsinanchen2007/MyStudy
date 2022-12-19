/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define ITEM_VALID 1
#define ITEM_INVALID 0
#define RETURN_OK 0
#define RETURN_ERROR 1
#define ITEM_MAX_LEN 3
#define IP_MAX_ITEM_NUM 4
#define IP_ORIGIN_STR_MAX_LEN 12
#define IP_ORIGIN_STR_MIN_LEN 4

 // ip地址的某个域段元素。需要进栈
 typedef struct tagIP_ITEM_INFO {
    int value; /* ip域段值 */
    int index; /* 该域段在ip地址中的位置 */
    int flag; /* 是否已扩展*/
    char val_str[ITEM_MAX_LEN+1];
    char str_residue[IP_ORIGIN_STR_MAX_LEN+1]; /* 剩余str,该str 实际上超过12个有效字符就不可能返回ip地址了 */
 } IP_ITEM_INFO_S;

// ip地址域段栈空间模拟
#define STACK_MAX_SIZE 64
 IP_ITEM_INFO_S g_ip_item_stack[STACK_MAX_SIZE] = {0};
int g_stack_top = -1; // 栈顶

int stack_pop()
{  
    if (g_stack_top >= STACK_MAX_SIZE || g_stack_top == 0) return RETURN_ERROR;     
    (void)memset(&(g_ip_item_stack[g_stack_top--]), 0, sizeof(IP_ITEM_INFO_S));
    return RETURN_OK;
}

int stack_enter(IP_ITEM_INFO_S *enter)
{
    if (enter == NULL) return RETURN_ERROR;
    if (g_stack_top >= STACK_MAX_SIZE-1) return RETURN_ERROR;  
    (void)memcpy(&(g_ip_item_stack[++g_stack_top]), enter, sizeof(IP_ITEM_INFO_S));
    return RETURN_OK;
}

IP_ITEM_INFO_S *get_stack_top()
{
    if (g_stack_top >= STACK_MAX_SIZE) return NULL;    
    return &(g_ip_item_stack[g_stack_top]); 
}

int is_valid_item(IP_ITEM_INFO_S *item)
{
    if (((item->value <= 9) && (strlen(item->val_str) == 1)) ||
       ((item->value > 9) && (item->value <= 99) && (strlen(item->val_str) == 2)) ||
       ((item->value > 99) && (item->value <= 255) && (strlen(item->val_str) == 3))) {
        return ITEM_VALID;
    }
    return ITEM_INVALID;
}

int get_one_item_from_str(char *str, int str_len, int item_width, int item_index, IP_ITEM_INFO_S *one_item)
{    
    if (item_width > str_len) return RETURN_ERROR; // 位宽不能超过剩余长度
    (void)memcpy(one_item->val_str, str, item_width);    
    one_item->value = atoi(one_item->val_str);
    one_item->index = item_index;
    one_item->flag = 0;    
    (void)memcpy(one_item->str_residue, str+item_width, str_len-item_width);
    //printf("\r\n2---%d, %d, %d, %s;", one_item->index, one_item->value, one_item->flag, one_item->str_residue); 
    return RETURN_OK;
}

int ip_store(char **ip_array, int num, int last_item)
{
    int i;
    int len = 0;
    char *ptr = (char *)malloc(24);

    if (ptr == NULL) return RETURN_ERROR;
    memset(ptr, 0, 24);
    for (i = 1; i < STACK_MAX_SIZE; i++) {
       //printf("\r\n%d,%d", i, g_ip_item_stack[i].flag);
       if (g_ip_item_stack[i].flag == 1) {
            len += sprintf(ptr+len, "%d.", g_ip_item_stack[i].value);
            //printf("\r\n%s,%d", ptr,i);
        }
    }
    len += sprintf(ptr+len, "%d", last_item);
    ip_array[num] = ptr;
    //printf("\r\n%s", ip_array[num]);
    return RETURN_OK;
}

/* 深度优先遍历+回溯 */
char ** restoreIpAddresses(char * s, int* returnSize)
{
    IP_ITEM_INFO_S first_item = {0};
    IP_ITEM_INFO_S next_item = {0};
    IP_ITEM_INFO_S *cur_item;
    int value_width;
    int ret;
    char **ip_array;
    int all_num = 0;

    if (strlen(s) > IP_ORIGIN_STR_MAX_LEN || strlen(s) < IP_ORIGIN_STR_MIN_LEN) {
        *returnSize = 0;
        return NULL;
    }
    
    ip_array = (char **)malloc(sizeof(char **)*1024);
    if (ip_array == NULL) return NULL;

    first_item.value = -1; //栈底元素只是作为判断是否完成的标记
    first_item.index = 0;
    first_item.flag = 0;
    memset(first_item.val_str, 0, sizeof(first_item.val_str));
    (void)memcpy(first_item.str_residue, s, strlen(s));
    (void)stack_enter(&first_item);
    g_stack_top = 0;
    
    /* 对每个栈顶元素的剩余字符串，进行宽度为1、2、3的is_vaild_item判断，valid的元素入栈；若三个宽度都是invalid， 则栈顶元素出栈，继续判断下一个栈顶元素*/
    do {
        cur_item = get_stack_top();        
        if (cur_item->flag == 1) {
            //printf("\r\n%s, %d, %d, %s;", cur_item->val_str, cur_item->index, cur_item->flag, cur_item->str_residue); 
            stack_pop();
        } else {   
            cur_item->flag = 1;            
            for (value_width = 1; value_width <= ITEM_MAX_LEN; value_width++) {                
                memset(&next_item, 0, sizeof(IP_ITEM_INFO_S));
                ret = get_one_item_from_str(cur_item->str_residue, strlen(cur_item->str_residue), value_width, cur_item->index+1, &next_item);                
                // 已经取不到宽度为value_width的元素了
                if (ret == RETURN_ERROR) {                       
                    break;
                }                    
                if (is_valid_item(&next_item) == ITEM_VALID) {                      
                    if (next_item.index >= IP_MAX_ITEM_NUM) {
                        if (strlen(next_item.str_residue) == 0) {
                            ip_store(ip_array, all_num, next_item.value);  
                            all_num++;
                        } 
                    } else {
                        stack_enter(&next_item);
                        //printf("\r\n%s, %d, %s, %d;", next_item.val_str, next_item.index, next_item.str_residue, g_stack_top);   
                    }
                }        
            }    
        }
    } while (g_stack_top != 0);

    *returnSize = all_num;
    //printf("\r\n%d", all_num);
    return ip_array;
}