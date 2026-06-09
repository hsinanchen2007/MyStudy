#define MAX_FILENUM 20000
#define MAX_FILENAME_LEN 150
#define MAX_CONETENTNAME_LEN 150

void getfilecontent(char * paths, int start , int end, char *ret){
    char tmp[MAX_CONETENTNAME_LEN] = {0};  
    int len = end - start + 1;
    memcpy(tmp , &paths[start], len );
    for(int i = 0 ; i < len ; i++){
        if(tmp[i] == '('){
            start = i;
        }
        if(tmp[i] == ')'){
            end = i;
        }
    }
    len = end - start -1;
    memcpy(ret, &tmp[start + 1],len );
    return ; 
}
void getfilename(char *paths , char * root ,int start ,int end, char *ret){
    char tmp[MAX_FILENAME_LEN] = {0};    
    int len = end - start + 1;
    memcpy(tmp , &paths[start+1], len );
    for(int i = 0 ; i < len ; i++){
        if(tmp[i] == '('){
            end  = i;           
            break;
        }
    }
    tmp[end] = '\0';
    char *add = "/";
    memcpy(ret, root, strlen(root));
    ret[strlen(root)] = '\0';
    strcat(ret , add);
    strcat(ret , tmp);
    return ;
}
typedef struct my_hash_s{
    const char *key;
    int  con_num;
    UT_hash_handle hh;
}my_hash;

typedef struct my_link {
    char *file;
    struct my_link *pnext;
};

typedef struct my_content {
    char content[MAX_CONETENTNAME_LEN];           
    struct my_link link;
    int linknum;
};

struct my_content g_astContent[MAX_FILENUM];
int g_ContentNum = 0;
my_hash *users = NULL;

void delete_all() {
  my_hash *current_user, *tmp;
  HASH_ITER(hh, users, current_user, tmp) {
    HASH_DEL(users,current_user);  
    free(current_user);            
  }
}
void init_content(int pathsSize) {
    for (int i = 0 ; i < MAX_FILENUM ; i++){
       memset(g_astContent[i].content, 0, MAX_CONETENTNAME_LEN);
       g_astContent[i].link.pnext = NULL;
       g_astContent[i].link.file = NULL;
       g_astContent[i].linknum = 0;
    }
    g_ContentNum = 0;
    delete_all();
    return;
}

void addlink (struct my_content *c, char *filename) {
    struct my_link *tmp = NULL;
    int filenameSize = 0 ;
    filenameSize = strlen(filename) + 1;
    tmp = malloc(sizeof(struct my_link));
    tmp->file = malloc(sizeof(char) * filenameSize);
    memset(tmp->file, 0, filenameSize);
    memcpy(tmp->file,  filename, filenameSize);
    tmp->pnext = c->link.pnext;
    c->link.pnext = tmp;
    return;
}
void add_content(char *filename, char * content) {
    int contentSize = 0 ;
    my_hash *node = NULL;
    contentSize = strlen(content) +  1;
    /*第一次直接添加到content中*/
    if (g_ContentNum == 0) {
        memcpy(g_astContent[g_ContentNum].content,  content, contentSize);
        addlink(&g_astContent[g_ContentNum], filename);
        g_astContent[g_ContentNum].linknum ++;
        g_ContentNum ++;
        node = malloc(sizeof(my_hash));
        node->key = content;
        node->con_num = 1;
        HASH_ADD_STR(users,key, node);
        return;  
    }
    /*在content中如果找到相同内容就只添加filename*/
    HASH_FIND_STR(users, content, node);
    if(node != NULL){
        //可能会有哈希冲突
        if( strncmp(content ,g_astContent[node->con_num-1].content ,contentSize  ) == 0) {
            addlink(&g_astContent[node->con_num-1], filename);
            g_astContent[node->con_num-1].linknum ++;
            return;
        }
    }

    /*否则添加content与filename*/
    memcpy(g_astContent[g_ContentNum].content,  content, contentSize);
    addlink(&g_astContent[g_ContentNum], filename);
    g_astContent[g_ContentNum].linknum ++;
    g_ContentNum ++;
    node = malloc(sizeof(my_hash));
    node->key = content;
    node->con_num = g_ContentNum;
    HASH_ADD_STR(users, key, node);
    return;    
}

char *** findDuplicate(char ** paths, int pathsSize, int* returnSize, int** returnColumnSizes){
    int first = 0;
    char root[MAX_FILENAME_LEN] = {0};
    char content[MAX_CONETENTNAME_LEN] = {0};
    char filename[MAX_FILENAME_LEN] = { 0};
    int loop = 0;
    int start = 0;
    int end = 0;
    int len = 0;
    int out_num = 0;
    struct my_link *p = NULL;
    g_ContentNum = 0;  
    my_hash *users = NULL;
    
    //初始化全局变量
    init_content(pathsSize);

    for(int i = 0; i < pathsSize ; i++){
        first = 0;
        start = 0;
        end = 0;
        for(int j = 0 ; j < strlen(paths[i]); j++){
            if(paths[i][j] == ' '){
                if(first == 0){
                    first = j;
                    memcpy(root , &paths[i][0] , j + 1 );
                    root[j] = '\0';
                }
                start = j;
            }
            if(paths[i][j] == ')'){
                end = j;
                memset(content, 0 , MAX_CONETENTNAME_LEN);
                //获取文件内容
                getfilecontent(paths[i] , start, end , content);
                memset(filename, 0 , MAX_FILENAME_LEN);
                //获取文件名称
                getfilename(paths[i], root, start, end, filename);
                add_content(filename, content);
            }            
        }
    }
    //输出
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_FILENUM);
    memset(*returnColumnSizes, 0, MAX_FILENUM );
    char *** ret = (char ***)malloc(sizeof(char **)* MAX_FILENUM);
    loop = 0;
    int j = 0;
    for (int i = 0; i < g_ContentNum ; i ++){
        if (g_astContent[i].linknum <= 1){
            continue;
        }
        ret[j] = (char **)malloc(sizeof(char*) * g_astContent[i].linknum);
        (*returnColumnSizes)[j] = g_astContent[i].linknum;
        p = &g_astContent[i].link;
        loop = 0;
        while(p->pnext){
            p = p->pnext;
            len = strlen(p->file) + 1;
            ret[j][loop] = malloc(sizeof(char)*len);
            memcpy(ret[j][loop], p->file, len);
            loop ++;
        }
        j++;
        out_num ++;
    }
    delete_all();
    *returnSize = out_num;
    if (out_num == 0){
       *returnColumnSizes = 0;
       return NULL; 
    }
    return ret;   
}