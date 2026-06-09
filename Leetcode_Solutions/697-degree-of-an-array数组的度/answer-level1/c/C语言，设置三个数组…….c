哎，这道题真是想不出什么好办法，前前后后做了好几个小时。
# 解题思路：
拥有相同大小的度的子数组，说明子数组要有这个度的数。同时又要长度最短，所以当这个子数组两侧是这个度的数时才能长度最短。我的第一个想法是找出数组中出现频次最高的数，接着从数组两侧往内缩小范围，不是该数则删去，从而得到拥有该数的最小子数组。
但这个想法有个问题，出现频次最高的数未必只有一个，例如示例1的[1, 2, 2, 3, 1]，频次最高的数是1或2，若是1，长度为5，若是2，长度为2，若按这个想法运行，最后输出的会是5，所以不行。
第二个想法是，新建一个degree数组记录nums中各个数的度，再遍历degree数组，找到最大度的数，将包含该数的子数组依次比较，得到最短长度。那每找到一个最大度的数，都要遍历一遍nums来得出它的左右区间，这样太费时间，所以再新建两个数组，储存每个数第一次及最后一次出现的位置。

# 具体实现：
1.设置变量temp，代表nums当前位置为i的数。每一次循环时，将degree[temp]加一。如果degree[temp]为1，说明temp第一次出现，则记录first[temp]为i。然后每次循环都更新last[temp]为i，因为i是不断增大的，所以每一次循环都是temp最后出现的位置。
2.在循环时，同时设置maxdegree，记录曾出现的最大度。还有max，记录nums的最大数，这样当遍历degree数组时，查找到max就够了，后面不需要查找了。
3.循环遍历一遍degree数组，当等于maxdegree时，比较当前数所在的子数组的长度，即最后一次位置减去第一次位置+1，取较小者。
4.返回这个最小的长度。


```
int findShortestSubArray(int* nums, int numsSize){
    if(numsSize == 0 || numsSize == 1)
    return numsSize;
    //分别标记一个数的度，及它出现的第一次和最后一次的位置
    int* degree = (int*)calloc(50000, sizeof(int));
    int* first = (int*)calloc(50000, sizeof(int));
    int* last = (int*)calloc(50000, sizeof(int));
    int i, temp, max=0, maxdegree = 0;
    for(i=0; i<numsSize; i++){
        temp = nums[i]; //储存数组当前的数
        degree[temp]++; //该数出现的度加一
        if(degree[temp] > maxdegree)
        maxdegree = degree[temp]; //记录数组的最大度

        if(degree[temp] == 1)//记录第一次出现的位置
        first[temp] = i;

        last[temp] = i; //记录最后一次的位置

        if(temp > max) //记录数组中出现过的最大数
        max = temp;

    }
    int minlen = INT_MAX;
    for(i=0; i<=max; i++){ //遍历度的数组时，查找到最大数就够了
        if(degree[i] == maxdegree){ //查找到最大度时，取最小长度
            temp = 1 + last[i] - first[i];
            minlen = minlen < temp ? minlen : temp;
        }
    }
    return minlen;
}
```
