从左到右遍历整个数。如果遇到一个6，则将其替换为9并结束遍历。最后返回该数。
```
class Solution {
    public int maximum69Number (int num) {
        char[] array = String.valueOf(num).toCharArray();
        int length = array.length;
        for (int i = 0; i < length; i++) {
            if (array[i] == '6') {
                array[i] = '9';
                break;
            }
        }
        return Integer.parseInt(new String(array));
    }
}
```
