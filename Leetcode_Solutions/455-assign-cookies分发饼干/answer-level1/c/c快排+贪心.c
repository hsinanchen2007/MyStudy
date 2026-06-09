int comp(const void*a,const void*b)//用来做比较的函数。
{    return *(int*)a-*(int*)b;}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    int num=0;
    qsort(g,gSize,sizeof(int),comp);
    qsort(s,sSize,sizeof(int),comp);
    int j=0;
    for(int i=0; i<gSize; i++){
        if(j>=sSize){
            break;
        }
        while(j<sSize){
            if(s[j]<g[i]){
                j++;
            }else{
                j++;
                num++;
                break;
            }
        }
    }
    return num;
}