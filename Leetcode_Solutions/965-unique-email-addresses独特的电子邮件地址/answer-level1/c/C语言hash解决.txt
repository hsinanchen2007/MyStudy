```
typedef struct {
    char addr[110];
    UT_hash_handle hh;
} HASHSET;
int numUniqueEmails(char ** emails, int emailsSize){
    HASHSET *hash = NULL;
    int count=0;
    for(int i=0; i<emailsSize; i++) {
        HASHSET* tmp = (HASHSET*)malloc(sizeof(HASHSET)); 
        int len = strlen(emails[i]);
        int index = 0;
        int flag=0;
        
        for(int j=0; j<len; j++){
            if(emails[i][j]=='@'){
                flag = j;
                break;
            }
        }

        for(int j=0; j<flag; j++) {
            if(emails[i][j]=='.') continue;
            if(emails[i][j]=='+'){
                break;
            }
            tmp->addr[index++] = emails[i][j];
        }
        for(int j=flag; j<len; j++) {
            tmp->addr[index++] = emails[i][j];
        }
        tmp->addr[index++] ='\0';

        HASHSET* isFind = NULL;
        if(i==0){
            HASH_ADD_STR(hash, addr, tmp);
            count++;
        }else{
            HASH_FIND_STR(hash, tmp, isFind);
            if(!isFind){
                HASH_ADD_STR(hash, addr, tmp);
                count++;
            }
        }
        
    }

    return count;
}
```
