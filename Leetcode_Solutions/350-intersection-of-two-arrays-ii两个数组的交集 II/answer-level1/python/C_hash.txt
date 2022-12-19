### 解题思路
冒泡排序与hash查找

### 代码
## 一、排序

```python []
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        i, j, res = len(nums1)-1, len(nums2)-1, []
        while i>=0 and j>=0:
            if nums1[i]>nums2[j]:
                i -= 1
            elif nums1[i]<nums2[j]:
                j -= 1
            else:
                res.append(nums1[i])
                i -= 1
                j -= 1
        return res
```
```c []
void buble_sort(int *arr, int len){
	int temp,i,j,flag=1;
	for(i=0;i<len-1&&flag;i++){
		flag = 0;
		for(j=0;j<len-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
				flag=1;
			}
		}
	}
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	if(nums1>nums2) return intersect(nums2, nums2Size, nums1, nums1Size, returnSize);
	buble_sort(nums1, nums1Size);
	buble_sort(nums2, nums2Size);
	int *res=(int*)malloc(sizeof(int)*nums1Size);
	*returnSize=0;
   nums1Size--;nums2Size--;
	while(nums1Size>=0&&nums2Size>=0){
		if(nums1[nums1Size]>nums2[nums2Size]) nums1Size--;
		else if(nums1[nums1Size]<nums2[nums2Size]) nums2Size--;
		else{
			nums2Size--;
			res[(*returnSize)++]=nums1[nums1Size--];
		}
	}
	return res;
}
```

# python,collections.Counter字典交集，骚的不得行
结果击败6.03% ??

```python3 []
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        from collections import Counter
        return list((Counter(nums1) & Counter(nums2)).elements())
```

# hash,内存占用大
```python []
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        size1, size2 = len(nums1), len(nums2)
        if size1 > size2:
            nums1, nums2 = nums2, nums1
            size1, size2 = size2, size1
        c1 = {}
        for i in range(size1):
            c1[nums1[i]] = c1.get(nums1[i], 0) + 1
        res = []
        for i in nums2:
            if i in c1 and c1[i] > 0:
                res.append(i)
                c1[i] -= 1
        return res
```
```c []
struct hash{
    int key;
    int value;
    UT_hash_handle hh;
};
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if(nums1>nums2) return intersect(nums2, nums2Size, nums1, nums1Size, returnSize);
    int i;
    struct hash *table=NULL,*p=NULL;
    for(i=0;i<nums1Size;i++){
        HASH_FIND_INT(table, &nums1[i], p);
        if(!p){
            p=(struct hash*)malloc(sizeof(struct hash));
            p->key=nums1[i];
            p->value=1;
            HASH_ADD_INT(table, key, p);
        }else p->value += 1;  // 找到直接添加
    }
    *returnSize=0;  // 官方这里不知道他是不是0！必须加
    int *res=(int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums2Size;i++){
        HASH_FIND_INT(table, &nums2[i], p);
        if(p&&p->value>0){
        	res[(*returnSize)++]=nums2[i];
        	p->value--;
		}
    }
    return res;
}
```
