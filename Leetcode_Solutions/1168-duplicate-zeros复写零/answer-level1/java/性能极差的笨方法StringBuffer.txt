特别笨的办法，利用StringBuffer的特性 把数组转成String 然后进行复写零并截取字符串。
此代码只考虑实现，不考虑性能。
```
class Solution {
    public void duplicateZeros(int[] arr) {
        int[] newArr = new int [arr.length];
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i <arr.length ; i++) {
            if (arr[i] == 0) {
                buffer.append(arr[i]).append(0);
            }else{
                buffer.append(arr[i]);
            }
        }
        String substring = buffer.substring(0, arr.length);
        for (int i = 0; i < substring.length(); i++) {
            int i1 = Integer.parseInt(substring.charAt(i)+"");
            arr[i] = i1;
        }
    }
}
```
