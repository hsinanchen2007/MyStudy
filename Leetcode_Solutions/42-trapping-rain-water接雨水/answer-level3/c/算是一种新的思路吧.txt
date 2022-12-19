本解是先找出数组中最大的元素，然后分左右两边找出次大的元素，求这两个元素中能装的雨水的量，然后再递归求解。其中，每次取最大的元素比较费时。
```
int raintrapleft(int *height, int heightSize,int left, int right);
int raintrapright(int *height, int heightSize,int left, int right);
int findmax(int *height,int left, int right);
int trap(int* height, int heightSize){
    int left=0, right=heightSize-1;
    if(heightSize<=2){
        return 0;
    }
    int highestpos=findmax(height,left,right);          //找最大值
    return raintrapleft(height,heightSize,left,highestpos)+raintrapright(height,heightSize,highestpos,right);
}

int raintrapleft(int *height, int heightSize,int left, int right){      //左递归
    if(left==right||left==right-1){
        return 0;
    }
    int highest1=findmax(height,left,right-1);          //找最大值
    int volumn=0;
    for(int i=highest1+1;i<right;i++){
        volumn=volumn+height[highest1]-height[i];     
    }    
    volumn=volumn+raintrapleft(height,heightSize,left,highest1);
    return volumn; 
}

int raintrapright(int *height, int heightSize,int left, int right){    //右递归 
    if(left==right||left==right-1){
        return 0;
    }
    int highest1=findmax(height,left+1,right);          //找最大值
    int volumn=0;
    for(int i=left+1;i<highest1;i++){
        volumn=volumn+height[highest1]-height[i]; 
    }
    volumn=volumn+raintrapright(height,heightSize,highest1,right);
    return volumn; 
}

int findmax(int *height,int left, int right){
    int maxcolumn=-1,pos;           //这里maxcolumn=-1是保证pos一定会取到值
    for(int i=left;i<=right;i++){
        if(height[i]>maxcolumn){
            maxcolumn=height[i];
            pos=i;
        }
    }
    return pos;
}
```
