先对arr1进行计数排序，遍历arr2中的数值并输出，最后再输出arr2中没有的值
![1122.png](https://pic.leetcode-cn.com/b2268c14b426d6300c3029f9a03920b88c09aa533be0d46e2ca1ccaccb9db259-1122.png)

class Solution {
   public static int[] relativeSortArray(int[] arr1, int[] arr2) {
        int min = arr1[0], max = arr1[0];
        for(int i = 1; i < arr1.length; i++) {
            if(arr1[i] < min)
                min = arr1[i];
            if(arr1[i] > max)
                max = arr1[i];
        }
        int[] result = new int[max - min + 1];
        int[] result2 = new int[arr1.length];
        Arrays.fill(result, 0);
        for(int i = 0; i < arr1.length; i++) {
            result[arr1[i] - min]++;
        }
        int index=0;
        for(int i = 0; i < arr2.length; i++) {
            while(result[arr2[i] - min] > 0) {
                result2[index++] = arr2[i];
                result[arr2[i] - min]--;
            }
        }
        for(int i = 0; i < result.length; i++) {
            while(result[i] > 0) {
                result2[index++] = i+min;
                result[i]--;
            }
        }
        return result2;
    }
}