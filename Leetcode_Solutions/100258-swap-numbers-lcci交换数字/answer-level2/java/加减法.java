一个值为a，另一个为b
先a + b存到第一个值，然后第二个值b - (a + b) = -a，这个时候把负数转为整数就完成了把第一个值放到第二个存储空间
然后用第一个存储空间还是a + b，减去a就是b了
交换完成

class Solution {
    public int[] swapNumbers(int[] numbers) {
        numbers[0] += numbers[1];
        numbers[1] -= numbers[0];
        numbers[1] *= -1;
        numbers[0] -= numbers[1];
        return numbers;
    }
}