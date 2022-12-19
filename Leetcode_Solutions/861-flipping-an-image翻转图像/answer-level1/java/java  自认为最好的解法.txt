若原位置两数为0与1(或1与0),则进行水平翻转,再反转图像会使原位置仍然为0与1(或1与0),所以直接不进行变换
原位置两数相同时直接取反,使用位运算^,0变1,1变0
```
public int[][] flipAndInvertImage(int[][] A) {
        for (int[] arr : A) {
            int l = 0, r = arr.length - 1;
            while (l < r) {
                if (arr[l] == arr[r]) {
                    arr[l] ^= 1;
                    arr[r] = arr[l];
                }
                l++;
                r--;
            }
            if (l == r) arr[l] ^= 1;
        }
        return A;
    }
```
