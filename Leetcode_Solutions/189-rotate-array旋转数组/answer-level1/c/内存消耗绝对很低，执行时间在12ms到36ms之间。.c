### 解题思路
我是渣渣。
### 代码

```c
void rotate(int* nums, int numsSize, int k){
    if(k==0 || numsSize==1 || numsSize==0 || numsSize==k){return;}

    int n=numsSize%k;
    int gys=0;
    int a1=numsSize;
    int a2=k;
        
    if(n!=0){
        while(true){
        if(a1>a2){
            a1=a1%a2;
            if(a1==0){gys=a2;break;}
            }
            else{a2=a2%a1;if(a2==0){gys=a1;break;}}
        }
    }
    else{if(numsSize>k){gys=k;}else{gys=numsSize;}}
        for (int j = 0; j < gys; j++) {
            int temp = nums[j];
            for (int i = 0; i < numsSize/gys - 1; i++) {
                nums[(-i * k+j + numsSize * k) % numsSize] = nums[(-i * k - k +j+                               numsSize * k) % numsSize];
            }
            nums[(k+j) % numsSize] = temp;
        }
    
}

```