1. 用hash表存键盘位置数据
2. 优化使用长度为26的数组存键盘位置数据

```
class Solution {
    public int calculateTime(String keyboard, String word) {
        int[] arr = new int[26];
        char[] keyboardCharArr = keyboard.toCharArray();
        for(int i = 0;i<keyboardCharArr.length;i++){
            char c=keyboardCharArr[i];
            arr[c-'a'] = i;
        }
        
        int result = 0;
        int preIndex = 0;
        char[] wordCharArr = word.toCharArray();
        for(int i = 0;i<wordCharArr.length;i++){
            char c=wordCharArr[i];
            result += Math.abs(arr[c-'a'] - preIndex);
            preIndex = arr[c-'a'];
        }
        return result;
        
    }
}
```
