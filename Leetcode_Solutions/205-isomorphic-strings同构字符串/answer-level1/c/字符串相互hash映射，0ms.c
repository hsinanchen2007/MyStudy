1.s(key)->t(value)
2.t(key)->s(value)
如果两次映射都是一对一，则是同构。

![c.PNG](https://pic.leetcode-cn.com/1a83ff171e33c440c437bd3948a0fdc97c1350ed869b2a436c7c22a42c9cf7ab-c.PNG)

```
#define HASH_LEN 128   //ascii码数值0-127
typedef struct HashNode{
    char key;
    char val;
    int num;   
}Node_t;

bool isIsomorphic(char * s, char * t){  
    int len = strlen(s);  
    if(len<2) return true;
    
    Node_t s_key[HASH_LEN] = {0};
    Node_t t_key[HASH_LEN] = {0};
    
    for(int i = 0;i<len;i++){
        if(s_key[s[i]].num == 0){
           s_key[s[i]].key = s[i];
           s_key[s[i]].val = t[i]; 
           s_key[s[i]].num = 1;
        }
        else if(s_key[s[i]].num == 1){
            if(s_key[s[i]].val != t[i])
                return false;            
        }                
    }
    
    for(int i = 0;i<len;i++){
        if(t_key[t[i]].num == 0){
           t_key[t[i]].key = t[i];
           t_key[t[i]].val = s[i]; 
           t_key[t[i]].num = 1;
        }
        else if(t_key[t[i]].num == 1){
            if(t_key[t[i]].val != s[i])
                return false;            
        }                
    }
    
    return true;
}

```
