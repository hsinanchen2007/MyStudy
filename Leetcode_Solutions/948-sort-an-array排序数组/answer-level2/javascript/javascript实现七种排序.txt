### 解题思路
javascript实现冒泡排序，选择排序，插入排序，希尔排序，归并排序（递归），快速排序（递归），堆排序

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
//冒泡排序
/***
var sortArray = function(nums) {    
    for (let i =nums.length-1,temp; i >= 0;i--){
        for(let j = 0; j < i; j++){
            if(nums[i]<nums[j]){
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    return nums;
}; */
//选择排序
/**
var sortArray = function(nums) {
    for(let i = 0,temp,min; i < nums.length; i++){
        min = nums[i];
        for(let j = i+1; j < nums.length; j++){
            if(min > nums[j]){
                temp = min;
                min = nums[j];
                nums[j] = temp;
            }
        }
        nums[i] = min;
    }
return nums;
}; */

//插入排序
/**
var sortArray = function(nums) {
    for(let i = 1; i <nums.length; i++){//i前是排序好的，i后是未排序的
        curr = nums[i]
        let j = i - 1;//在内层循环外可以用j，就不用每次交换，直接到合适位置插入。
        for(; j >= 0; j--){
            if(curr >= nums[j] ){
                break;//更快结束循环
            }
              nums[j+1] = nums[j];//j+1是因为curr取出来所以可以顺序覆盖
        }
        nums[j+1] = curr;////j+1是因为内层循环-1后才发现<0，所以退出。所以需要加回去
    }
    return nums;
};
 */

//希尔排序
/**重点是理解
var sortArray = function(nums) {
    //没有math的库，但是可以用js原生的parseInt!
    for(let gap = parseInt(nums.length/2); gap > 0; gap = parseInt(gap/2)){
        //循环2是有几组要排序【错！】
         //循环2是从第gap个元素，逐个对其所在组进行直接插入排序操作
         //分组的意义不是专门分组比较，直接顺延往后走就行，而是分组的是比较对象
         //已排序的还是在前面，比较的还是和前面的比较
         //除了多一层gap变化的循环，内层的变化只是比较的间隔变大，由-1变-gap
        for(let i = gap; i< nums.length;i++){
            let j = i-gap;
            let min = nums[i];
            for(; j >= 0; j = j-gap ){
                if(min >= nums[j]){
                    break;
                }
                nums[j+gap]=nums[j];
                //min的值在最内层循环的不变，是插入排序！寻找的是j位置！
            }
            nums[j+gap]=min;
        }

    }
    return nums
}; */

//归并排序,递归
/** {
var sortArray = function(nums) {
    let len = nums.length;
    if(len<2){//递归结束条件！
        return nums;
    }
    let middle = parseInt(len/2);
    let left = nums.slice(0,middle);
    let right = nums.slice(middle);
    return merge(sortArray(left), sortArray(right));
};

var merge = function(left,right){//合并
    let result = [];
    while(left.length && right.length){
        if(left[0] < right[0]){
            result.push(left.shift());//可以对原数组进行修改
        }else{
            result.push(right.shift());
        }
    }

    if(left.length == 0){
        result = result.concat(right);//拼接
    }
    if(right.length == 0){
        result = result.concat(left);
    }
    return result;
};
}*/

//快速排序，递归
/*** 
var sortArray = function(nums) {
    var len = nums.length;
    if(len < 2){
        return nums;
    }
    let curr = nums[0];
    let left = [];
    let right = [];
    for(let i = 1; i < len; i++){
        if(nums[i] < curr){
            left.push(nums[i]);
        }else{
            right.push(nums[i]);
        }
    }
    result = sortArray(left).concat(curr,sortArray(right));
    return result;
};
*/

//堆排序//好难啊！！！！！！
var sortArray = function(nums) {
   //1.构建大顶堆
    for(let i = parseInt(nums.length/2-1);i >= 0;i--){
        //第一个非叶子结点是nums.length/2-1！
         //从第一个非叶子结点从下至上，从右至左调整结构
        adjustHeap(nums, i, nums.length);
    }

     //2.调整堆结构+交换堆顶元素与末尾元素
     for(let j = nums.length-1; j > 0; j--){
         //将堆顶元素与末尾元素进行交换。末尾的元素们就是已经排列好的了
         let temp = nums[0];
         nums[0] = nums[j];
         nums[j] = temp;
         adjustHeap(nums, 0, j);
     }
     return nums;
};

var adjustHeap = function(arr, i, len){
    let temp = arr[i];
    //从i结点的左子结点开始，也就是2i+1处开始
    for(let k = i*2+1; k < len ;k= k*2+1){//k=k*2+1，去到下一层的子节点。
    //如果左子结点小于右子结点，k指向右子结点
        if(k+1 < len && arr[k] < arr[k+1] ){
            k++;
        }
    //如果子节点k大于父节点i，将子节点值赋给父节点（不用进行交换）
        if(arr[k] > temp){
            arr[i] = arr[k];
            i = k;
        }
        else{
            break;
        }
    }
    arr[i] = temp;
};
```