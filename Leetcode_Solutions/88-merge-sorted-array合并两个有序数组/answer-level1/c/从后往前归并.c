### 解题思路
此处撰写解题思路
![捕获.JPG](https://pic.leetcode-cn.com/107aa654f87d112f44d81b4d7fe763fff71655de38cbbb2ad02c062ed3335f08-%E6%8D%95%E8%8E%B7.JPG)


### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int final_index=m+n-1; //合并后数组的长度
    int nums1_index=m-1;  //nums1当前索引位置
    int nums2_index=n-1;  //nums2当前索引位置
    while(final_index>=0)
    {
        if((nums1_index>=0)&&(nums2_index>=0))
        {
            if(nums1[nums1_index]>nums2[nums2_index])            //nums1中的数字大放入最终位置
            {
                nums1[final_index--]=nums1[nums1_index--];
            }else{                                               //nums2中的数字大放入最终位置
                nums1[final_index--]=nums2[nums2_index--];
            }
        }else if(nums1_index<0){                                 //nums1中的已经全部放完放剩下的nums2
            nums1[final_index--]=nums2[nums2_index--];
        }else{                                                   //nums2中的已经全部放完nums1已经是有序的可以退出
            break;
        }
    }
    return 0;
}
```