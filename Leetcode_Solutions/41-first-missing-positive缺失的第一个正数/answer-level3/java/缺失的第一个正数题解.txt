# 写在前面：
- 算法设计基础：n表示给定数组的长度缺失的第一个正数一定在小于或等于n+1中的数能找到
- 自己设定boolean数组用于记录下标对应的数是否出现过，它的第一个元素下标为零，最后遍历时不遍历，因为0不是正数

# 思路与代码：
```
/* 1.创建长度为n+1的boolean类型的数组 */
int n = nums.length; // 给定数组的长度
boolean[] judge = new boolean[n + 1];// 加1是为了使下标能与元素组的元素相对应，故judge[0]可以不理
/* 2.遍历原数组，找到大于0且小于n+1的数，对应着其值找到boolean数组的下标，并使该元素值为true */
for (int num : nums) {
    if (num > 0 && num < n + 1) {
        judge[num] = true;
    }
}
/* 3.从下标为1的元素开始遍历boolean数组，找到第一个值为false的元素，返回其下标，否则返回n+1，即为缺失的第一个正数 */
int flag = 1;
for (; flag < judge.length; flag++) {
    if (judge[flag] == false) {
        return flag;
    }
}
flag = n + 1;
return flag;
```

