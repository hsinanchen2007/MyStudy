### 解题思路
此处撰写解题思路

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    //二维数组指针，指针的列数，每一列元素的个数
    //一个一个放置立方体
    int sum=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            int k=*(*(grid+i)+j);
            if(k>0){
                sum=sum+2+4*k;//直接放置长方体  
            }
            if(j!=0&&*(*(grid+i)+j-1)>0){//前面
                if(*(*(grid+i)+j-1)>=k){   
                    sum-=(2*k);
                }else{
                    sum-=(2*(*(*(grid+i)+j-1)));
                }
            }
            if(i!=0&&*(*(grid+i-1)+j)>0){//左面
                if(*(*(grid+i-1)+j)>=k){   
                    sum-=2*k;
                }else{
                    sum-=2*(*(*(grid+i-1)+j));
                }
            }

        }
            
        
    }
    return sum;
}      

```