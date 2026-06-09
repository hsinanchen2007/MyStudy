```
class Solution {
    public int minimumSwap(String s1, String s2) {
        char[] arr1 = s1.toCharArray();
        char[] arr2 = s2.toCharArray();
        if (arr1.length != arr2.length) return -1;
        int xy = 0, yx = 0;
        for (int i=0; i<arr1.length; i++) {
            if (arr1[i] == 'x' && arr2[i] == 'y')
                xy++;
            else if (arr1[i] == 'y' && arr2[i] == 'x')
                yx++;
        }
        if ((xy + yx) % 2 != 0) return -1;
        return xy / 2 + yx / 2 + (xy % 2) * 2;
    }
}
```