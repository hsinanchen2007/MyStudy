### 解题思路
此处撰写解题思路
![图片.png](https://pic.leetcode-cn.com/1f1fa1d6a89045a108267fefdb60b705fe55aa6a2bbc76f34461c2701de0aee7-%E5%9B%BE%E7%89%87.png)

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i=0;i<n;i++){
		int j=m-1;
		for(;j>=0;j--){
			if(nums2[i]<nums1[j]){
				nums1[j+1]=nums1[j];
			}else{
                break;
            }
		}
		nums1[j+1]=nums2[i];
		m++;
	}
}
```