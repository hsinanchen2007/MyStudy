### 解题思路

冲撞问题没解决, 但是一开始让内存大一点就可以, 如果有人知道怎么解决冲撞问题可以留言...

### 代码

```c
#define COUNT 54

typedef struct hashmap{
    char c;
    int num;
    struct hashmap *next;
} dict;

void put(char c, dict *bucket){
    if(bucket->c == '\0'){
        bucket->c = c;
        bucket->num= 1;
    }else{
        if(bucket->c == c){
            bucket->num++;
        }else{
            void init(dict *);
            init(bucket->next);
            put(c, bucket->next);
        }
    }
}

void init(dict *bucket){
    bucket->c = '\0';
    bucket->num = 0;
    bucket->next = NULL;
}

int getNumSum(dict *bucket){
    if(bucket==NULL){
        return 0;
    }
    return bucket->num/2*2 + getNumSum(bucket->next);
}

int all_even(dict *bucket){
    if(bucket==NULL) return 0;
    if(bucket->num%2==0){
        return all_even(bucket->next);
    }else{
        return 1;
    }
}

int longestPalindrome(char * s){
    if(*s=='\0') return 0;
    dict alphabet[COUNT];
    // init dict
    for(int i=0;i<COUNT;i++){
        init(&alphabet[i]);
    }

    while (*s!='\0'){
        int positon = *s % COUNT;
        put(*s, &alphabet[positon]);
        s++;
    }

    int res = 0;

    for(int i=0;i<COUNT;i++){
        if(all_even(&alphabet[i])&&res%2==0){
            res += 1;
        }
        res += getNumSum(&alphabet[i]);
    }
    return res;
}
```