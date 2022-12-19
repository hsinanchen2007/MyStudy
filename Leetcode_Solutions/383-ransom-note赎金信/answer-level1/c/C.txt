bool canConstruct(char * ransomNote, char * magazine){
    for(int i = 0; i < strlen(ransomNote); i++)
    {
        char* j;
        if(j = strchr(magazine,ransomNote[i]))
            *j = 'A';
        else
            return false;
    }
    return true;
}