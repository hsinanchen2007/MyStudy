### 解题思路
设置三个指针，从后往前遍历
flag_num1指向num1中最后一个有效数字
flag_num2指向num2中最后一个有效数字
p指针指向num1的末尾，用于存放num1和num2指针指向中相对大的数字
直到num2中的数字全部写入num1结束
### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    if(m==0)
    {
        for(int i=0;i<n;i++)
        {
            nums1[i]=nums2[i];
        }
        return;
    }
    else if(n==0)
        return;

    int p=nums1Size-1;//p指向num1的末尾
    int flag_num1=m-1,flag_num2=n-1;//两个flag分别指向最后一个有效数字
    while(flag_num2!=-1)
    {
        if(flag_num1==-1||nums1[flag_num1]<=nums2[flag_num2])
        {
            nums1[p]=nums2[flag_num2];
            flag_num2--;
            p--;
        }
        else if(nums1[flag_num1]>nums2[flag_num2])
        {
            nums1[p]=nums1[flag_num1];
            if(flag_num1!=-1)
                flag_num1--;
            p--;
        }
        
    }
}







```