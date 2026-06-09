### 解题思路
回溯法本质就是不停的试探，利用递归提升效率
需要提供一个数据空间记录之前的尝试结果

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int ipindex = 0;
static int dotpos[3] = {0};

bool check_ip(char* s,int len)
{
    int num;

    if (s==NULL)
        return false;

    //printf("check:%s \n", s);
    num = atoi(s);
    switch (len) {
        case 1:
            if (num>=0 && num < 10)
                return true;
            else
                return false;
            break;
        case 2:
            if (num>=10 && num < 100)
                return true;
            else
                return false;
            break;
        case 3:
            if (num>=100 && num < 256)
                return true;
            else
                return false;
            break;
        default:
            return false;
            break;
    }
}
void copyip(char *ip, char *s, int len)
{
    int j = 0;
    int k = 0;

    for (int i = 0;i < len; i++){
        if (k<3 && i == dotpos[k]) {
            ip[j++]='.';
            k++;
        }
        ip[j++] = s[i];
    }
    ip[j]='\0';
    printf("%s \n", ip);
    return;
}

//回溯函数
void rollback(char *s, int len, int prev_pos, int dot_index, char **ret_ip)
{
    bool flag = false;
    char temp[16]={0};

    if (dot_index == 3){
        strncpy(temp,s+prev_pos,strlen(s+prev_pos));
        flag = check_ip(temp,strlen(temp));
        if (flag) {
            for (int i = 0;i < 3; i++) {
                printf("%d ", dotpos[i]);
            }
            printf("\n");
            ret_ip[ipindex] = (char *)malloc(sizeof(char)*16);
            memset(ret_ip[ipindex],0,sizeof(char)*16);
            copyip(ret_ip[ipindex],s,len);
            ipindex++;
        }
        return;
    }

    int max_pos = (len>prev_pos+4) ? prev_pos+4 : len;

    for (int curr_pos = prev_pos+1;curr_pos<max_pos;curr_pos++) {
        //printf("curr pos %d,dot index %d\n", curr_pos, dot_index);
        dotpos[dot_index] = curr_pos;
        strncpy(temp,s+prev_pos,curr_pos-prev_pos);
        flag = check_ip(temp,strlen(temp));
        if (flag) {
            rollback(s, len, curr_pos, dot_index+1,ret_ip);
            dotpos[dot_index] = 0;
        }
    }
}

char ** restoreIpAddresses(char *s, int* returnSize)
{
	int s_len = strlen(s);
    char **ret_ip = NULL;
    printf("len %d\n",s_len);
    if (s_len < 4 || s_len>12) {
        *returnSize = 0;
        return NULL;
    }

    ipindex = 0;
    ret_ip = (char **)malloc(sizeof(char*)*20);
    rollback(s,s_len,0,0,ret_ip);
    //printf("%d\n",ipindex);
    *returnSize = ipindex;
    //printf("end %d\n",ipindex);
    return ret_ip;
}
```