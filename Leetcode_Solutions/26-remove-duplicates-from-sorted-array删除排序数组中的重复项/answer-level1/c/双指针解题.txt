### 解题思路
**首先**排除数组长度小于1的数组，为的是将空数组单独考虑，
**然后**申明两个指向数组的指针，它们初始指向的都是数组初始地址，接着pt指向每次遍历的元素，p指向找到的非重复数
### 代码

```c


int removeDuplicates(int* nums, int numsSize){
    int i = 1;
    int *p,*pt;//声明的两个指针
    if(numsSize <= 1) return numsSize;//排除数组长度小1的数组
    p = pt = nums;
    for(;i < numsSize;i++) {
       if(*pt != *++pt)//当前指针pt指向的值不等于下一个指针指向的值时，执行下面语句
         *++p = *pt;  //将当前指针pt指向的值(注意上面的pt已经自增)赋值给p指针指向的位置 
    }
    return p - nums + 1;//由于p - t只算了差值没有算本身，所以需要加1
}


```