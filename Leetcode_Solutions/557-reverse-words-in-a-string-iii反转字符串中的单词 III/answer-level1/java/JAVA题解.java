执行用时 :4 ms, 在所有 Java 提交中击败了99.81%的用户
内存消耗 :37.6 MB, 在所有 Java 提交中击败了97.15%的用户

```
class Solution {
    public String reverseWords(String s) {
        char[] arr = s.toCharArray();
        int arrLen = arr.length;
        int start = 0;
        for(int i = 0; i < arrLen; i++) {
            if(arr[i] == ' ') {
                reverse(arr,start,i-1);
                start = i + 1;
            } else if(i == arrLen - 1) {
                reverse(arr,start,arrLen - 1);
            }
        }
        return new String(arr);
    }
    
    public void reverse(char[] arr,int start,int end) {
        while(start < end) {
            char temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start ++;
            end --;
        }
    }
}
```
