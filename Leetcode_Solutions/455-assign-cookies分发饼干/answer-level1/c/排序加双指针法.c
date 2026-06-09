### 解题思路
如题

### 代码

```c

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int a[],int size){
    int flag=0;
    for(int i=0;i<size;i++){
         flag=0;
        for(int j=0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                flag=1;
                swap(&a[j],&a[j+1]);
            }
        }
        if(flag==0)
          break;
    }
}
void move(int a[],int k,int size){
    for(int i=k+1;i<size;i++){
        a[i-1]=a[i];
    }
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    sort(g,gSize);
    sort(s,sSize);
    int count=0;
    int i=0,j=0;
    while(i<gSize&&j<sSize){
        if(g[i]<=s[j]){
            count++;
            i++;
            j++;
        }
        else{
            j=j+1;
        }
    }
    return count;
}
```