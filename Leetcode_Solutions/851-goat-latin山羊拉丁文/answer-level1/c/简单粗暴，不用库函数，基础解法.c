char arr_aeiou[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
char result[1408];
bool is_aeiou(char temp)
{
    for(char i = 0; i < 10; i++) {
        if (temp == arr_aeiou[i]) {
            return true;
        }
    }
    return false;
}

char * toGoatLatin(char * S){
    int index_w = 0;
    unsigned char index = 0;
    unsigned char last_temp;
    char i;
    char word_idx = 0;

    while(S[index]) {
        if (S[index] == ' ') {
            index++;
            continue;
        }
        word_idx++;
        if(is_aeiou(S[index])) {
            while((S[index] != ' ') && (S[index] != 0)) {
                result[index_w++] = S[index++];
            }
        } else {
            last_temp = S[index++];
            while((S[index] != ' ') && (S[index] != 0)) {
                result[index_w++] = S[index++];
            }
            result[index_w++] = last_temp;
        }
        result[index_w++] = 'm';
        for(i = 0; i <= word_idx; i++) 
        {
            result[index_w++] = 'a';
        }
        result[index_w++] = ' ';
    }
    result[--index_w] = 0;
    return result;
}