### 简单粗暴,暴力解法

![微信截图_20200329234246.png](https://pic.leetcode-cn.com/8e571697c432430cbbc4e314bbb94f2ae17865008c604c06e36cc4922f50977f-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200329234246.png)

**解题思路**:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;若相等返回索引
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;若小返回当前索引,若大再次进行比较,没有的话放到最后

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    for (int i = 0; i < numsSize;i++) {
            if (*(nums+i) >= target) {
                return i;
            }
        }
        return numsSize;
}
```