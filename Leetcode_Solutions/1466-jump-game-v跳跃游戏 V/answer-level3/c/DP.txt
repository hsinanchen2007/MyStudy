### 解题思路

执行用时 :60 ms, 在所有 C 提交中击败了18.18%的用户
内存消耗 :7.9 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
int jump(int* arr, int arrSize, int d, int *jumps, int pos){
    //printf("pos%d\n",pos);
    if(pos<0||pos>=arrSize){
        return 0;
    }
    if(jumps[pos]!=0){
        return jumps[pos];
    }
    if(pos==0){
        if(pos+1>=arrSize||arr[pos]<arr[pos+1]){
            jumps[pos]=1;
            return 1;
        }
    }
    else if(pos==arrSize-1){
        if(pos-1<0||arr[pos]<arr[pos-1]){
            jumps[pos]=1;
            return 1;
        }
    }
    else{
        if(arr[pos]<arr[pos-1]&&arr[pos]<arr[pos+1]){
            jumps[pos]=1;
            return 1;
        }
    }
    int i;
    int maxjump=1;
    /*
    for(i=pos-d;i<=pos+d;i++){
        //不满足arr[i] > arr[j] 且 arr[i] > arr[k] ，其中下标 k 是所有 i 到 j 之间的数字
        if(arr[pos]<=arr[i]){
            continue;
        }
        int temp=jump(arr, arrSize, d, jumps, i)+1;
        maxjump=(maxjump>temp)?maxjump:temp;
    }
    */
    for(i=-1;i>=-d;i--){
        if((pos+i)<0||(pos+i)>=arrSize||arr[pos]<=arr[pos+i]){
            break;
        }
        int temp=jump(arr, arrSize, d, jumps, pos+i)+1;
        maxjump=(maxjump>temp)?maxjump:temp;
    }
    for(i=1;i<=d;i++){
        if((pos+i)<0||(pos+i)>=arrSize||arr[pos]<=arr[pos+i]){
            break;
        }
        int temp=jump(arr, arrSize, d, jumps, pos+i)+1;
        maxjump=(maxjump>temp)?maxjump:temp;
    }
    jumps[pos]=maxjump;
    return maxjump;
}

int maxJumps(int* arr, int arrSize, int d){
    //dp[i] = 1 + max (dp[j])
    if(arr==NULL||arrSize==0){
        return 1;
    }
    int *jumps=(int *)malloc(sizeof(int)*arrSize);
    memset(jumps,0,sizeof(int)*arrSize);
    int i;
    for(i=arrSize-1;i>=0;i--){
        jump(arr, arrSize, d, jumps, i);
    } 
    //jump(arr, arrSize, d, jumps, arrSize-1);
    int maxjumps=0;
    for(i=0;i<arrSize;i++){
        //printf("%d ",jumps[i]);
        maxjumps=(maxjumps>jumps[i])?maxjumps:jumps[i];
    }
    return maxjumps;
}

//ERROR1:
//[3,3,3,3,3]
//3
//即最少为1次
//ERROR2:
//[66]
//1
//边界判断思考不够全面
```