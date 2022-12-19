```
#define max(a,b) ((a) > (b) ? (a) : (b))
int cmp(int a,int b) {
    if(a > b) {
        return 1;
    } else if(a < b) {
        return -1;
    } else {
        return 0;
    }
}

int maxTurbulenceSize(int* A, int ASize){
    int ans = 1;
    int anchor = 0;
    
    for(int i = 1;i < ASize;i++) {
        int c = cmp(A[i-1],A[i]);
        if(i == ASize - 1 || c * cmp(A[i],A[i+1]) != -1) {
            if(c != 0) {
                ans = max(ans,i - anchor + 1);
            }
            anchor = i;
        }
    }
    return ans;
}
```
