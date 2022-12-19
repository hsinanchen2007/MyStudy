### 解题思路
如题

### 代码

```c
void reverse(int a[],int l,int h){
  int p=l,q=h;
  while(p<q){
      int temp=a[p];
      a[p]=a[q];
      a[q]=temp;
      p++;
      q--;
  }
}


void rotate(int* nums, int numsSize, int k){
  int kreal=k%numsSize;
  if(numsSize==0||kreal==0) return;
  reverse(nums,0,numsSize-1);
  reverse(nums,0,kreal-1);
  reverse(nums,kreal,numsSize-1);
}
```