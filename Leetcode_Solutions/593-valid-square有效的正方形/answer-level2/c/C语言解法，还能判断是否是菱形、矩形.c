按照向量去计算，4个点，顶多有6种向量。
1、	计算不同两点之间向量，为了方便比较，计算时尽量让向量往y正半轴。
2、	排序向量，向量长度短的放前面，长度相同的，按x，y大小依次排序
3、	只需要看前4个向量，由于排序排好了就很方便了：
a.第1个向量和第2个向量不同 或者 第3个向量和第4个向量不同 ------->不是正方形
b. 满足a,第1个向量和第3个向量向量积不是0 ------>不是正方形 是菱形
c. 满足b和c,第1个向量和第3个向量长度不相等----------->不是正方形 是矩形

每个分支留的printf是为了好调试哪里的问题~

代码如下：
```
#define SPACE_SIZE 2
#define VECTOR_NUM 6
typedef struct{
    int x;
    int y;
    int abs;
}vector;

void CalVector(vector* out,int* pa, int* pb){
    int temp1 = pa[0]-pb[0];
    int temp2 = pa[1]-pb[1];
    if(temp1>0){
        out->x = temp1;
        out->y = temp2;
    }
    if(temp1<0){
        out->x = -temp1;
        out->y = -temp2;
    }
    if(temp1==0){
        if(temp2>=0){
            out->x = temp1;
            out->y = temp2;    
        }else{
            out->x = temp1;
            out->y = -temp2;            
        }
    }
    out->abs=temp1*temp1+temp2*temp2;
}

void Swap(vector* v1,vector* v2)
{
    v1->x = v1->x^v2->x;
    v2->x = v1->x^v2->x;
    v1->x = v1->x^v2->x;
    v1->y = v1->y^v2->y;
    v2->y = v1->y^v2->y;
    v1->y = v1->y^v2->y;
    v1->abs = v1->abs^v2->abs;
    v2->abs = v1->abs^v2->abs;
    v1->abs = v1->abs^v2->abs;
}

void SortVectors(vector* vectors){
    int i,j;
    int absi,absj;
    for(i=0;i<VECTOR_NUM;i++)
        for(j=i+1;j<VECTOR_NUM;j++){
            if((vectors[i].abs>vectors[j].abs)||((vectors[i].abs==vectors[j].abs)&&(vectors[i].x>vectors[j].x))||((vectors[i].abs==vectors[j].abs)&&(vectors[i].y>vectors[j].y)&&(vectors[i].x==vectors[j].x))){
                Swap(&vectors[i],&vectors[j]);
            }   
        }
}

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size){
    if((p1Size!=SPACE_SIZE)||(p2Size!=SPACE_SIZE)||(p3Size!=SPACE_SIZE)||(p4Size!=SPACE_SIZE)){
        printf("!!!!!\n");
        return false;
    }
    vector *vectors =(vector *)malloc(VECTOR_NUM*sizeof(vector));
    CalVector(&vectors[0],p1,p2);
    CalVector(&vectors[1],p1,p3);
    CalVector(&vectors[2],p1,p4);
    CalVector(&vectors[3],p2,p3);
    CalVector(&vectors[4],p2,p4);
    CalVector(&vectors[5],p3,p4);
    
    for(int i=0;i<6;i++){
        printf("vectors[%d]x is %d, y is %d\n",i,vectors[i].x,vectors[i].y);        
    }
    printf("----------\n");
    SortVectors(vectors);
    for(int i=0;i<6;i++){
        printf("vectors[%d]x is %d, y is %d, abs is %d\n",i,vectors[i].x,vectors[i].y,vectors[i].abs);        
    }
    if((vectors[0].x!=vectors[1].x)||(vectors[0].y!=vectors[1].y)||(vectors[2].x!=vectors[3].x)||(vectors[2].y!=vectors[3].y)){
        printf("`````\n");
        return false;
    }
    if((vectors[0].x*vectors[2].x+vectors[0].y*vectors[2].y)!=0){
        printf("####\n");
        return false;
    }
    if((vectors[0].abs!=vectors[2].abs)||(vectors[0].abs==0)||(vectors[2].abs==0)){
        printf("&&&&&\n");
        return false;
    }
    return true;
}

```
