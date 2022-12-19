直接快排，然后比较两个数组，完全一致即可
int cmp(void *x, void *y)
{
    return *(char *)x - *(char *)y;
}

bool CheckPermutation(char* s1, char* s2){
    int sz1,sz2,i;
    sz1 = strlen(s1);
    sz2 = strlen(s2);
    if (sz1 != sz2){
        return false;
    }
    qsort(s1, sz1, sizeof(char), cmp);
    qsort(s2, sz2, sizeof(char), cmp);
    for (i=0; i<sz1;i++){
        if(s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}