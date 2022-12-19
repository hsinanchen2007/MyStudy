int* maxDepthAfterSplit(char * seq, int* returnSize){
    int i, len, depth = 0;

    len = strlen(seq);

    int *answer = malloc(sizeof(int) * len);

    for (i = 0; i < len; i++) {
        if (seq[i] == '(') {
            depth++;
            answer[i] = depth % 2;
        } else if (seq[i] == ')'){
            answer[i] = depth % 2;
            depth--;
        }
    }
    *returnSize = len;
    return answer;
}