这题用C真是恶心、、、
![捕获.PNG](https://pic.leetcode-cn.com/eab3527f56da98dc9fd548d02fab75f95561ebc2aa428d32340a7a34103579fd-%E6%8D%95%E8%8E%B7.PNG)


```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int root_index;
    char name[20];
    int frequency;
} name_fre;

int Cmp_names(const void * a, const void * b)
{
    name_fre * c = (name_fre *)a;
    name_fre * d = (name_fre *)b;
    return strcmp(c->name, d->name);
}

int FindRoot(name_fre* NAMES, int index)
{
    int son = index;
    int temp;
    int index_temp = index;
    
    if (NAMES[index_temp].root_index == index_temp) { // 根是自身
        return index_temp;
    }

    while (NAMES[index_temp].root_index != index_temp) { // 找到root
        index_temp = NAMES[index_temp].root_index;
    }
    
    while (son != index_temp) { // 路径压缩，每个节点都连接到根节点上，节省查找时间
        temp = NAMES[son].root_index; // 当前名字的根节点
        NAMES[son].root_index = index_temp;
        son = temp;
    }
    
    return index_temp;
}

void UnionRoot(name_fre* NAMES, int index1, int index2)
{
    int a = FindRoot(NAMES, index1);
    int b = FindRoot(NAMES, index2);

    if (a != b) {
        if (strcmp(NAMES[a].name, NAMES[b].name) < 0) { // 选择字典序最小的字符串作为根节点
            NAMES[b].root_index = a;
            NAMES[a].frequency +=  NAMES[b].frequency;
            NAMES[b].frequency = 0;
        } else {
            NAMES[a].root_index = b;
            NAMES[b].frequency +=  NAMES[a].frequency;
            NAMES[a].frequency = 0;
        }
    }
}

int FindName(name_fre* NAMES, int name_number, char * name)
{
    int low = 0;
    int high = name_number - 1;
    while(low < high)
    {
        int mid = (low + high) / 2;
        if (strcmp(NAMES[mid].name, name) < 0) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

void UnionName(name_fre* NAMES, int name_number, char * name1, char * name2)
{
    int name1_index = FindName(NAMES, name_number, name1);
    int name2_index = FindName(NAMES, name_number, name2);

    if (name1_index == name2_index) {
        return;
    }
    // union根节点
    UnionRoot(NAMES, name1_index, name2_index);

}

char** trulyMostPopular(char** names, int namesSize, char** synonyms, int synonymsSize, int* returnSize)
{
    name_fre NAMES[namesSize];
    int ret_index = 0;
    char ** ret = (char**)malloc(namesSize * sizeof(char*));

    for (int i = 0; i < namesSize; i++) {
        memset(NAMES[i].name, '\0', 20);
        NAMES[i].frequency = 0;
        NAMES[i].root_index = -1; 
    }
    // 将名字和频率写成结构体
    for (int i = 0; i < namesSize; i++) {
        int s_len = strlen(names[i]);
        for (int j = 0; j < s_len; j++) {
            if ((names[i][j] >= 'a' && names[i][j] <= 'z') 
                || (names[i][j] >= 'A' && names[i][j] <= 'Z')) {
                NAMES[i].name[j] = names[i][j];
            } else if (names[i][j] >= '0' && names[i][j] <= '9'){
                NAMES[i].frequency = 10 * NAMES[i].frequency + (names[i][j] - '0');
            }
        }
    }

    qsort(NAMES, namesSize, sizeof(name_fre), Cmp_names);

    for (int i = 0; i < namesSize; i++) {
        NAMES[i].root_index = i; // 初始化时根节点是自己
    }

    // 读取名字对
    for (int i = 0; i < synonymsSize; i++) {
        char name1[20], name2[20];
        memset(name1, '\0', 20);
        memset(name2, '\0', 20);
        int s_len = strlen(synonyms[i]);
        int flag = 0, index1 = 0, index2 = 0;
        for (int j = 0; j < s_len; j++) {
            if ((synonyms[i][j] >= 'a' && synonyms[i][j] <= 'z') 
                || (synonyms[i][j] >= 'A' && synonyms[i][j] <= 'Z')) {
                if (!flag) {
                    name1[index1++] = synonyms[i][j];
                } else {
                    name2[index2++] = synonyms[i][j];
                }
            }
            if (synonyms[i][j] == ',') {
                flag = 1;
            }
        }
        // 查找名字的根节点
        UnionName(NAMES, namesSize, name1, name2);
    }
    
    // 将频率不为0的名字输出
    for (int i = 0; i < namesSize; i++) {
        if (NAMES[i].frequency == 0) {
            continue;
        }
        ret[ret_index] = (char *)malloc(30 * sizeof(char));
        int s_len = strlen(NAMES[i].name);
        int fre = NAMES[i].frequency;
        char fre_str[10] = {'\0'};
        memcpy(ret[ret_index], NAMES[i].name, s_len);
        ret[ret_index][s_len] = '(';
        sprintf(fre_str, "%d", fre); // 将整数转为字符串
        int fre_len = strlen(fre_str);
        memcpy(&ret[ret_index][s_len + 1], fre_str, fre_len);
        ret[ret_index][s_len + fre_len + 1] = ')';
        ret[ret_index][s_len + fre_len + 2] = '\0';
        ret_index++;
    }
    * returnSize = ret_index;
    return ret;
}
```
