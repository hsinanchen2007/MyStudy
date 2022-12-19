```
typedef struct TagRecord{
    struct TagRecord *next;
    char tag[12];
}TagRecord, *stack;
bool isValid(char * code){
    //判断标签合法
    //判断<> </> 或CDATA
    //判断字符被标签所包含
    char t[12];
    int stack_num = 0, i, j;
    stack s = (stack)malloc(sizeof(struct TagRecord));
    stack tmp;
    s->next = NULL;
    while('\0' != *code){
        if(*code == '<'){
            code++;
            if(*code != '/' && *code != '!'){
                for(i = 0; *code >= 'A' && *code <= 'Z';i++,code++){
                    t[i] = *code;
                }
                if(i==0 || i > 9 || ((*code < 'A' || *code > 'Z') && *code != '>'))
                    return false;
                stack_num++;
                tmp = (stack)malloc(sizeof(struct TagRecord));
                tmp->next = s->next;
                s->next = tmp;
                for(j = 0; j < i; j++){
                    tmp->tag[j] = t[j];
                }
            }else if(*code == '/'){
                if(0 == stack_num)
                    return false;
                code++;
                tmp = s->next;
                for(i = 0;tmp->tag[i] == *code; i++,code++)
                    continue;
                if(*code != '>')
                    return false;
                s->next = tmp->next;
                stack_num--;
                free(tmp);
            }else{
                if(0 == stack_num)
                    return false;
                if(*(code++)!='!')
                    return false;
                if(*(code++)!='[')
                    return false;
                if(*(code++)!='C')
                    return false;
                if(*(code++)!='D')
                    return false;
                if(*(code++)!='A')
                    return false;
                if(*(code++)!='T')
                    return false;
                if(*(code++)!='A')
                    return false;
                if(*(code++)!='[')
                    return false;
                while(!(*code=='\0' || (*code==']'&&*(code+1)==']'&&*(code+2)=='>')))
                    code++;
                if(*code == '\0')
                    return false;
                code+=2;
            }
        }
        if(*(++code)!='\0' && 0 == stack_num)
            return false;
    }
    if(stack_num == 0)
        return true;
    return false;
}
```
