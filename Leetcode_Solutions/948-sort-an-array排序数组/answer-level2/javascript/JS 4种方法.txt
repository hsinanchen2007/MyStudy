### 解题思路
冒泡排序 插入排序 选择排序 归并排序

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    //冒泡排序  time:o(n)²  space o1  将最大的放到最右边
    // for (let i = 0; i < nums.length; i++) {
    //     let isSorted = false;//如果内层未进行排序证明数组已经有序
    //     for (let j = 0; j < nums.length - i - 1; j++) {
    //         if (nums[j] > nums[j+1]) {
    //             isSorted = true;
    //             swap(nums,j,j+1)
    //         }
    //     }
    //     if (!isSorted) {
    //         break;
    //     }
    // }
    //选择排序  time:o(n)²  space o1 
    //选择排序大致的思路是找到数据结构中的最小值并 将其放置在第一位，接着找到第二小的值并将其放在第二位，以此类推（原地排序算法）
    // let { length } = nums;
    // let min;
    // for (let i = 0; i < length; i++) {
    //     min = i;
    //     for(let j = i; j < length; j++){ //j要从i开始 因为前面的都已经排过序了
    //         if(nums[min] > nums[j]) {
    //             min = j;
    //         }
    //     }
    //     if(i !== min) {
    //         swap(nums,i,min)
    //     }
    // }
    //归并排序 time:O(nlogn)  space: o(n)
//     if(nums.length > 1) {
//         let middle = Math.floor(nums.length / 2);
//         let left = sortArray(nums.slice(0,middle));
//         let right = sortArray(nums.slice(middle));
//         nums = merge(left,right)
//     }
//     return nums;
// };
// function merge(left,right){
//     const result = [];//合并两个有序数组
//     while(left.length && right.length) {
//         result.push(left[0] <= right[0] ? left.shift() : right.shift());
//     }
//     return result.concat(left,right);
//插入排序每次排一个数组项，以此方式构建最后的排序数组。假定第一项已经排序了。接着，它和第二项进行比较：第二项是应该待在原位还是插到第一项之前呢？这样，头两项就已正确排序，接着和第三项比较（它是该插入到第一、第二还是第三的位置呢），以此类推 ps:排序小型数组时，此算法比选择排序和冒泡排序性能要好 time(on²)
    const length = nums.length;
    let temp;
    for(let i = 1; i< length;i++){
        let j = i;
        temp = nums[i]
        while(j>0 && nums[j-1] > temp){ //往前看
            nums[j] = nums[j-1];
            j--;
        }
        nums[j] = temp
    }
    return nums;
}
//交换函数
function swap(arr,v1,v2) {
    let temp = arr[v1];
    arr[v1] = arr[v2];
    arr[v2] = temp;
}
```