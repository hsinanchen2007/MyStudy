

int maxNumberOfBalloons(char * text){
    int len = strlen(text);
    int hash_table[26]; //记录各字母出现次数的Hash表
    int index;
    int min = 10000;
    
    //Hash表初始化
    for(int i=0;i<26;i++){
        hash_table[i] = 0;
    }
    
    for(int j;j<len;j++){
        index = text[j] - 'a';
        hash_table[index] += 1;
    }
    
    hash_table[11] = hash_table[11]/2;
    hash_table[14] = hash_table[14]/2;
    
    min = hash_table[0] < min ? hash_table[0] : min;
    min = hash_table[1] < min ? hash_table[1] : min;
    min = hash_table[11] < min ? hash_table[11] : min;
    min = hash_table[13] < min ? hash_table[13] : min;
    min = hash_table[14] < min ? hash_table[14] : min;
    
    return min;
    
}