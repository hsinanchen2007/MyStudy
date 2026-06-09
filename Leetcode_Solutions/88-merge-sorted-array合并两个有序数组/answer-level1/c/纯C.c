### 解题思路
![智慧联想浏览器截图20200329210420.png](https://pic.leetcode-cn.com/0796e82cdbf249458699967742f73f2114adb2376f73e41c85aba34d428d89b2-%E6%99%BA%E6%85%A7%E8%81%94%E6%83%B3%E6%B5%8F%E8%A7%88%E5%99%A8%E6%88%AA%E5%9B%BE20200329210420.png)


### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        while(nums1[j]<nums2[i]&&j<m+i)
        {
            j++;
        }
        if(j<m+i)
        {
            int q=m+i;
            for(q;q>j;q--)
            {
                nums1[q]=nums1[q-1];
            }
            nums1[j]=nums2[i];
        }else{
            for(;i<n;i++)
            {
                nums1[j++]=nums2[i];
                break;
            }
        }

    }
}
```