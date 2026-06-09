### 解题思路
此处撰写解题思路

### 代码

```c
int thirdMax(int* nums, int numsSize){
    if(numsSize==1) return nums[0];
    int i,j,a,b,c,n,cnt;
    a=nums[0]; n=numsSize;
    for(i=1,cnt=1;(i<n)&&(cnt<3);i++){
        if(cnt==1&&nums[i]!=a){
            if(nums[i]>a){
                b=a; a=nums[i];
            }
            else{
                b=nums[i];
            }
            cnt++;
        }
        if(cnt==2&&nums[i]!=a&&nums[i]!=b){
            if(nums[i]<b) {
                c=nums[i];
            }
            else if(nums[i]<a&&nums[i]>b){
                c=b; b=nums[i];
            }
            else{
                c=b; b=a; a=nums[i];
            }
        cnt++;
        }
    }
    if(cnt<3) return a;
    while(i<n){
        if(nums[i]>a){
            c=b; b=a; a=nums[i];
        }
        else if(nums[i]<a&&nums[i]>b){
            c=b; b=nums[i];
        }
        else if(nums[i]<b&&nums[i]>c){
            c=nums[i];
        }
        i++;
    }
    return c;
}
```