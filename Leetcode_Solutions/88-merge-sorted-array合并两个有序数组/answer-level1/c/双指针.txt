### 解题思路
i在num1上遍历，j在num2上遍历

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i,j,k;
    i=j=0;
    while(i<m&&j<n){    
        if(nums1[i]<=nums2[j]){    //移动i至在nums1中第一个比nums2[j]大的位置
            i++;
        }
        else {
            for(k=m-1;k>=i;k--)nums1[k+1]=nums1[k]; //将nums1中i之后的元素后移
            nums1[i]=nums2[j]; //将元素nums2[j]插入到i之前
            j++;m++;
        }
    }
    if(j<=n-1){     //排除[1,2,3,0,0,0]，[2,5,6]，即i遍历完后nums2[]中还有数据
    for(;i<nums1Size;i++,j++)nums1[i]=nums2[j];
    }
}
```