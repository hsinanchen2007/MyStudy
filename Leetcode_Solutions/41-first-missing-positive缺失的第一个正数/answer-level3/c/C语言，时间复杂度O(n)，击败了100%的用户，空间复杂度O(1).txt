![image.png](https://pic.leetcode-cn.com/296ac4cf915ec4f9d6059b7e9a0144ef081b7caaa159199a50b1e5771ec037f2-image.png)

### 解题思路
1、正常数据的话，数组元素值应该是[1,2,3,4,5]连续的数，异常情况为[1,2,4,5]
2、正常数据我们认为0下标应该存放1，1下标存放2...
3、遍历数组，找到 `1<=元素<=数组长度`的元素，如5，将他放到应该放置的位置，即4号索引
4、遇到范围之外的数值，如-1 或者超过数组长度的值，不交换，继续下一个
5、处理之后的数据为[1,2,4,5]，再遍历一遍数组，`下标+1`应该是正确值，找出第一个不符合的即可



### 代码

```c
// tips: 正整数从1开始，初步换序后，a[0]应为1，a[1]应为2

int firstMissingPositive(int* nums, int numsSize){
  // 换序的过程即将数换到正确位置的过程，最多换n个，故复杂度为O(n)
  for (int i = 0; i < numsSize; i++) {
    // 该数字不属于当前位置 交换a[i] 和a[i]-1位置上的数字
    while ((nums[i] >= 1 && nums[i] <= numsSize) && (nums[i] != nums[nums[i]-1])) {
      int tmp = nums[i];
      nums[i] = nums[tmp-1];
      nums[tmp-1] = tmp;
    }
  }

  // 默认缺少的是正整数是 数组长度+1
  int is = numsSize + 1;

  // 如果中间有缺少的，直接替换is
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != (i + 1)) {
      is = i + 1;
      break;
    }
  }

  return is;
}
```