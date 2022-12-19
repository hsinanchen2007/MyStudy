
暴力法：1.遍历到0放到最后，数组整体向前移一位。(太复杂了)
2.创建新数组，先一次遍历排好非0数值，再一次遍历把0排好，再一次遍历把新数组的值依次赋给旧数组。(稍微好点)
以下是暴力法1


```c
void moveZeroes(int* nums, int numsSize){
	int i=0;
	int j=0;
	if(numsSize==1||numsSize==0){
		return *nums;
	}
	int total=0;
	for(i=0;i<numsSize;i++){
	    if(nums[i]==0){
            total++;
            for(j=i;j<numsSize-1;j++){
                nums[j]=nums[j+1];
            }
            nums[numsSize-1]=0;
            i--;
        }
        if(i>=numsSize-total-1){
            break;
        }
    }
}

```


以下是暴力法2
```c
void moveZeroes(int* nums, int numsSize){
	int *a=(int*)malloc(sizeof(int)*numsSize);
	int i,j=0,k;
	for(i=0;i<numsSize;i++){
		if(nums[i]!=0){
			a[j++]=nums[i];
		}
	}
	for(;j<numsSize;j++){
		a[j]=0;
	}
 	for(k=0;k<numsSize;k++){
		nums[k]=a[k];
	}
   	free(a);
}
```


双指针法，快指针遍历所有元素，慢指针停留在最后一个非零元素处。快指针每次碰到一个非零元素就放到满指针身后。最后用0填充剩下的位置。
```c
void moveZeroes(int* nums, int numsSize){
	int lastnonzero=-1;
	for(int i=0;i<numsSize;i++){
		if(nums[i]!=0){
			nums[++lastnonzero]=nums[i];
		}
	}
	for(int j=lastnonzero+1;j<numsSize;j++){
		nums[j]=0;
	}
}

```