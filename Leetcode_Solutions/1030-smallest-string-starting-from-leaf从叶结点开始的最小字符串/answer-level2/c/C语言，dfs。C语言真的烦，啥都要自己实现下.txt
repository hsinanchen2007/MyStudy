void str_reverse(char* str, int bufferSize){
    char temp;
    int i = 0;
    for(i = 0;i < bufferSize/2;i++){
        temp = str[i];
        str[i] = str[bufferSize-1- i];
        str[bufferSize-1- i] = temp;
    }
}
void find_small(struct TreeNode* root, char* buffer, char* small_str, int bufferSize){
    if(!root){
        return;
    }

    buffer[bufferSize++] = root->val + 'a';

    if((!root->left)&&(!root->right)){
        str_reverse(buffer,bufferSize);
        if(strlen(small_str)==0){
            strcpy(small_str, buffer);
        }
        if(strcmp(buffer,small_str) < 0){
            strcpy(small_str, buffer);
        }
        str_reverse(buffer,bufferSize);
        return;
    }
    else{
        find_small(root->left, buffer, small_str, bufferSize);
        find_small(root->right, buffer, small_str, bufferSize);
    }
    buffer[bufferSize] ='\0';
}
char * smallestFromLeaf(struct TreeNode* root){
    char* buffer = malloc(sizeof(char)*1024);
    char* small_str = malloc(sizeof(char)*1024);
    memset(buffer, '\0', sizeof(char)*1024);
    memset(small_str, '\0', sizeof(char)*1024);

    int bufferSize = 0;

    find_small(root, buffer, small_str, bufferSize);
    return small_str;
}