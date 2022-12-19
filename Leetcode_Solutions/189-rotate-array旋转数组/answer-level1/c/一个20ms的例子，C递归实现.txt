### 解题思路
![旋转数组.png](https://pic.leetcode-cn.com/a9bd0522141f8f93eb12812b93a1119f6556ceb9dd369f7861522f2f916fefc0-%E6%97%8B%E8%BD%AC%E6%95%B0%E7%BB%84.png)
注释有解释

### 代码

```c


void swap(int* a,int* b){//交换
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void rotate(int* nums, int numsSize, int k){
    if(numsSize==0) return;
    k=k%numsSize;//根据旋转的性质，当元素个数小于k时，得到合理的k值
    if(k==0) return;
    int start=numsSize-k;//从什么位置开始作旋转或交换
    int head=0;//数组的头部位置，要交换到的位置
    
    if(head!=numsSize-1){//递归终止
        while(start<numsSize){//当数组没有越界时
            swap(&nums[head++],&nums[start++]);//交换
        }
        
        rotate(nums+head,start-head,k);//重新解决剩余子序列元素的顺序
    }
}


```