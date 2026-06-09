char * minRemoveToMakeValid(char * s){
int len = strlen(s);
int a[1000] = {0};
int b[1000] = {0};
int i = 0;
int j = 0;
int k = 0;
int left = 0;
int right = 0;
char *returnStr = (char *)malloc(strlen(s)+1);
while (i < len) {
    if (s[i] == '(') {
        a[left++] = i;
    } else if (s[i] == ')') {
        if (left > 0) {
            left--;
        } else {
            b[right++] = i;
        }
    }
    i++;
}
i = 0; 
while(i < len) {
    int find = 0;
    for (j = 0; j < left; j++) {
        if (a[j] == i) {
            find = 1;
            break;
        }
    }
    if(find) {
        i++;
        continue;
    }
    find = 0;
    for (j = 0; j < right; j++) {
        if (b[j] == i) {
            find = 1;
            break;
        }
    }
    if(find) {
        i++;
        continue;
    }
    returnStr[k++] = s[i++];
}
returnStr[len-right-left] = 0;

return returnStr;
}