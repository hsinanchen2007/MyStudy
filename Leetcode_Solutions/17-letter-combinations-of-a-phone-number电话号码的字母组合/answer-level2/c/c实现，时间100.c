typedef struct key {
    int value;
    int digit_num;
    char digits[5];
} Key;

Key keys[] = {
    {2, 3, "abc"},
    {3, 3, "def"},
    {4, 3, "ghi"},
    {5, 3, "jkl"},
    {6, 3, "mno"},
    {7, 4, "pqrs"},
    {8, 3, "tuv"},
    {9, 4, "wxyz"}
};
void find_combination(char** ret_matrix, char* digits, char* result, int* curr_ret_num, int curr_digit_num)
{
    int i = 0;
    if (curr_digit_num >= strlen(digits)) {
        strncpy(ret_matrix[*curr_ret_num], result, strlen(digits) * sizeof(char));
        (ret_matrix[*curr_ret_num])[strlen(digits)] = '\0';
        (*curr_ret_num)++;
        return;
    }

    while (i < keys[digits[curr_digit_num] - '2'].digit_num) {
        result[curr_digit_num] = keys[digits[curr_digit_num] - '2'].digits[i];
        find_combination(ret_matrix, digits, result, curr_ret_num, curr_digit_num + 1);
        i++;
    }
}
char ** letterCombinations(char* digits, int* returnSize){
    int i;
    int ret_num = 1;
    int str_len = strlen(digits);
    int curr_ret_num = 0;
    char* result = NULL;

    if (digits == NULL || digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }

    for (i = 0; i < str_len; i++) {
        ret_num = ret_num * (keys[digits[i] - '2'].digit_num);
    }
    *returnSize = ret_num;
    char** ret_matrix = (char**)malloc(sizeof(char*) * ret_num);
    for (i = 0; i < ret_num; i++) {
        ret_matrix[i] = (char*)malloc(sizeof(char) * (str_len + 1));
        //memset(ret_matrix[i], 0 , sizeof(char) * (str_len + 1));
    }

    result = malloc(sizeof(char) * str_len);
    find_combination(ret_matrix, digits, result, &curr_ret_num, 0);

    return ret_matrix;
}