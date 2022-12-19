### 解题思路
利用UThash,边建立哈希表边检查

### 代码

```c
typedef struct HASH{
    int data;
    UT_hash_handle hh;
};

bool checkIfExist(int* arr, int arrSize){
    struct HASH *hashmp=NULL;
    struct HASH *s,*p;
    int i;
    for(i=0;i<arrSize;i++){
        int num1=arr[i]*2;      
        int num2=arr[i]%2==0?arr[i]/2:INT_MAX;  //求余是防止[1,3]这样的情况
        HASH_FIND_INT(hashmp,&num1,s);
        HASH_FIND_INT(hashmp,&num2,p);
        if(s==NULL&&p==NULL){
            s=(struct HASH*)malloc(sizeof(struct HASH));
            s->data=arr[i];
            HASH_ADD_INT(hashmp,data,s);
        }
        else return true;
    }
    return false;
}


//附上暴力解法,话说为什么暴力解法和hash用时一样
bool checkIfExist(int* arr, int arrSize){
    int i,j;
    for(i=0;i<arrSize-1;i++){
        for(j=i+1;j<arrSize;j++){
            if(arr[i]*2==arr[j]||arr[i]==arr[j]*2)
                return true;
        }
    }
    return false;
}
```