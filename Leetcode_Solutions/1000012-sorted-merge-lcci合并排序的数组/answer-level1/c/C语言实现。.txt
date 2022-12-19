### 解题思路![微信图片_20200303073003.png](https://pic.leetcode-cn.com/f5bf789872c35cec3b84737c21a6107eb885591b502bf626eb8bff4b7e2af4af-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200303073003.png)
首先我的程序是一个优化程度很低的程序，仅仅是个这个要求不多的题目；
首先在A的后面元素中依次将B中的元素添加进去，然后在A中进行依次冒泡排序就可以实现题目要求。
因为使用的冒泡排序 而冒泡的时间复杂度较高，因此执行时间比较长。推荐使用快排


### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
int pa=m,pb=0;
for(int i = 0; i < n; i++){
    A[pa]=B[pb];
    pa++;
    pb++;
}
for(int i = 0;i < ASize;i++){
    for(int j = i+ 1 ;j<ASize;j++){
        if(A[i]>A[j]){
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
       
    }
}

}
```