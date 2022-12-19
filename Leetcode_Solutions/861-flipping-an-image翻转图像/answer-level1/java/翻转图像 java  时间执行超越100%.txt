class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for (int i = 0; i < A.length; i++) {
            invertUsingFor(A[i]);
        }
        return A;
    }
     public int[] invertUsingFor(int[] array) {
        for (int i = 0; i < array.length / 2; i++) {
            int temp = array[i];
            array[i] = array[array.length - 1 - i];
            array[array.length - 1 - i] = temp;
        }
        for (int i = 0; i < array.length; i++) {
            array[i] ^= 1;
        }
        return array;
    }
}

针对每一行，进行先翻转，然后再翻转图像。翻转图像直接异或1就可以了。