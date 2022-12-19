### 解题思路
1. 从最后一位开始找出第一次出现递减的位置 index1,如果没找到说明已经是最大的序列了，需要进行反序
2. 找出递减位置后面刚好大于这个数字的位置 index2
3. 交换index1和index2
4. 将[index1 + 1, nums.length - 1] 进行升序排列

实例:
输入：[4, 2, 0, 2, 3, 2, 0]

1. 0 <= 2 <= 3 > 3,找到index1=3，nums[index1] = 2;
2. 3 - 2 = 1  2 - 2 = 0  0 - 2 = -2，仅大于2 为nums[4]=3, index2 = 4
3. 交换后  [4, 2, 0, 3, 2, 2, 0]
4. 对[index1 + 1, nums.length - 1]也就是范围[4, 6]排序，结果为[4,2,0,3,0,2,2]


### 代码

```javascript
    var nextPermutation = function (nums) {
      let i = nums.length - 1; //(0, nums.length - 1]
      //找出倒序递减的第一个数字，不存在则已经是最大数字了，需要逆序
      while(i > 0){
        if(nums[i] > nums[i - 1]){
          //找出[i, nums.leng - 1]范围中刚好大于nums[i - 1]的数字
          let j = i;//[i, nums.leng - 1]
          let exChangeIndex = i;
          let range = nums[i] - nums[i - 1];
          while(j <= nums.length - 1){
            let temp = nums[j] - nums[i - 1];
            if(temp > 0 && temp <= range){
              range = temp;
              exChangeIndex = j;
            }
            j ++;
          }

          //交换i-1, exChangeIndex
          let temp = nums[i - 1];
          nums[i - 1] = nums[exChangeIndex];
          nums[exChangeIndex] = temp;

          //[i, nums.length - 1] 排序
          quickSort(nums, i, nums.length - 1);

          return nums;
        }

        i --;
      }
      

      //反序
      for (let index = 0; index < Math.floor(nums.length / 2); index++) {
        let temp = nums[index];
        nums[index] = nums[nums.length - index - 1];
        nums[nums.length - index - 1] = temp;
      }

      return nums;
    };

    let quickSort = (nums, start, end) => {
      let l = start,
          r = end;  //[l, r]
      let temp = nums[start];
      let index = start;

      while(l < r){
        while(l < r){
          if(temp > nums[r]){
            nums[index] = nums[r];
            index = r --;
            break;
          }else{
            r --;
          }
        }

        while(l < r){
          if(temp < nums[l]){
            nums[index] = nums[l];
            index = l ++;
            break;
          }else{
            l ++;
          }
        }
      }
    
      nums[index] = temp;

      if(index - start > 1){
        quickSort(nums, start, index - 1);
      }
      if(end - index > 1){
        quickSort(nums, index + 1, end);
      }

      return nums;
    }
```