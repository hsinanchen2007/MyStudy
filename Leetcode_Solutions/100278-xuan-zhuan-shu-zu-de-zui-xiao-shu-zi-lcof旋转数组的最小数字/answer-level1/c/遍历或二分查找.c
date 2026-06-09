// 1. 方法一：遍历数组（该方法能够找到旋转点，并返回其值。）
// ```c
int minArray(int* numbers, int numbersSize){
    int ans = numbers[0];
    for (int i = 1; i < numbersSize; ++i) {
        if (numbers[i] < numbers[i - 1]) {
            ans = numbers[i];
            break;
        }
    }
    return ans;
}
// ```
// 2. 方法二：二分查找（尽管能够返回旋转点的值，但可能无法找到旋转点的位置，时间复杂度相较于方法一更低，[详解见大佬证明😊](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/)） 
// ```c
int minArray(int* numbers, int numbersSize){
    int i = 0, j = numbersSize - 1;
    while (i < j) {
        int m = (i + j) / 2;
        if (numbers[m] < numbers[j]) {
            j = m;
        }
        else if (numbers[m] > numbers[j]) {
            i = m + 1;
        }
        else {
            j -= 1;
        }
    }
    return numbers[i];
}
// ```

