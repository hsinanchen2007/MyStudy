bool canConstruct(char * ransomNote, char * magazine){
    int zimu[26]={0};
    int i;
    for(i=0;i<strlen(magazine);i++){
        zimu[magazine[i]-'a']++;
    }
    for(i=0;i<strlen(ransomNote);i++){
        zimu[ransomNote[i]-'a']--;
        if(zimu[ransomNote[i]-'a']<0)
            return false;
    }
    return true;
}