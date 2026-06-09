# 写在前面：
- 执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
- 解题思路：   
    1.从数组末尾开始向前循环遍历，以进位量temp=0为结束条件（temp初始值是1，及需要进位加一操作）
    2.遍历到每个元素，当数组元素为9且temp为1时，temp才能继续保持1，否则退出循环
    3.当数组元素全是9时，自然得在最前面多增一位数值为1的元素，其他元素置零

# 代码分析：
```
public static int[] plusOne(int[] digits) {
    int temp = 1;// 进位量
    for (int i = digits.length - 1; i >= 0; i--) { // 当数组元素为9且进位量为1时
        if (digits[i] == 9 && temp == 1) {
            digits[i] = 0;
        } else {
            digits[i]++;
            temp = 0;
        }
        if (temp == 0) {
            break;
        }
        if (i == 0) {
            int[] arr = new int[digits.length + 1];
            arr[0] = 1;
            return arr;
        }
    }
    return digits;
}
```
