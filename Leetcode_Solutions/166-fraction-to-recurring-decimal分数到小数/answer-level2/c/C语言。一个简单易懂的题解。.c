1. 先计算整数部分，由于整型溢出，先转成长整型，然后把符号也计算出来。两个数都转成正数。
2. 小数部分开始，记录每个被除数的值与当前位置，当出现被除数相等时，说明出现循环，找到被除数的位置，加上括号。
```cpp
struct HashMapNode {
    int key;
    int val;
    UT_hash_handle hh;
};

struct HashMapNode* hashMap = NULL;

int hashMapAdd(int key, int val) {
    struct HashMapNode* node;
    HASH_FIND_INT(hashMap, &key, node);
    if(node != NULL){
        return node->val;
    }
    
    node = (struct HashMapNode*)malloc(sizeof(struct HashMapNode));
    node->key = key;
    node->val = val;
    HASH_ADD_INT(hashMap, key, node);
    
    return -1;
}

char * fractionToDecimal(int numerator, int denominator){
    char* buf = (char*)malloc(sizeof(char) * 1024);
    int pos;
    long num = numerator, den = denominator;
    
    num = labs(num); den = labs(den);
    if(numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0){
        sprintf(buf, "-%ld", num / den);
    }else{
        sprintf(buf, "%ld", num / den);
    }
    
    pos = strlen(buf);
    num = num % den;
    if(num){
        buf[pos++] = '.';
        int start = -1;
        while(num && (start = hashMapAdd(num, pos)) == -1){
            buf[pos++] = (num * 10 / den) + '0';
            num = num * 10 % den;
        }
    
        if(start != -1){
            for(int i = pos++; i > start; i--){
                buf[i] = buf[i-1];
            }
            buf[start] = '(';
            buf[pos++] = ')';
        }
    }
    
    buf[pos] = '\0';  
    
    hashMap = NULL;
    return buf;
}
```
