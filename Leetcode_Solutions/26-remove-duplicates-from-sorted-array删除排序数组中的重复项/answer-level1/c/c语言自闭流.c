### 解题思路
执行用时 :1424 ms（还有谁！）, 在所有 C 提交中击败了5.03%的用户
内存消耗 :8.5 MB, 在所有 C 提交中击败了100.00%的用户

纪念一下我一上午的脑细胞，做出来就挺好，思路效率写法都挺可怕
malloc一个辅助数组a，遍历nums，出现重复就将当前下标之后的所有辅助数组下标都加1，重复个数temp++。在重新遍历一下nums，当一个数重复次数大于2，就将当前下标之后的所有辅助数组下标都减1，重复个数temp--，在将nums的下标减去其辅助数组的值的下标即为其真正位置。nums总长度减去重复数temp即为当前数组新长度。
### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int i,j,k,temp=0,number=0,*a,sign=0;
    a=(int *)malloc(numsSize*sizeof(int));
    for(i=0;i<numsSize;i++){
        a[i]=0;
    }
    for(i=0;i<numsSize;i++){
        number=nums[i];
        for(j=i+1;j<numsSize;j++){
            if(number==nums[j]){
                temp++;
                for(k=j+1;k<numsSize;k++){
                    a[k]=a[k]+1;
                }
            }
            else{
                continue;
            }
        }
    }
    for(i=0;i<numsSize;i++){
		number=nums[i];
		sign=0;
		for(j=i+1;j<numsSize;j++){
			if(number==nums[j]){
				sign++;
				if(sign>1){
					for(k=j+1;k<numsSize;k++){
						a[k]--;
					}
					sign--;
					temp--;
				}
			}
		}
	}
    for(k=0;k<numsSize;k++){
        nums[k-a[k]]=nums[k];
    }
    temp=numsSize-temp;
    return temp;
}
```