# 思路
* 先对每一个单词实现翻转，再对整个数组实现翻转。  
* 这样单词实现了两次翻转，所以单词个体的顺序仍不变，但单词间的顺序发生了变化。
```
class Solution {
    public void reverseWords(char[] str) {
        // 5ms
        // 原地修改，通过翻转实现
        if(str.length==0) return;
        int index = 0;
        for(int i=0;i<=str.length;i++){
            if(i==str.length || str[i]==' '){
                reverse(str,index,i); // 对每一个单词实现翻转
                index = i+1;
            }
        }
        reverse(str,0,str.length); // 整体翻转
    }
    
    private void reverse(char[] str, int start, int end){
        int cnt = 0;
        for(int i=start;i<(start+end)/2;i++){
            char t = str[i];
            str[i] = str[end-1-cnt];
            str[end-1-cnt] = t;
            cnt++;
        }
    }
}

// // 第一个想法
// 8ms
// class Solution {
//     public void reverseWords(char[] str) {
//         if(str.length==0) return;
//         String s = new String(str);
//         String[] list = s.split(" ");
//         StringBuilder sb = new StringBuilder();
//         for(int i=list.length-1;i>=0;i--){
//             sb.append(list[i]);
//             sb.append(" ");
//         }
//         for(int i=0;i<str.length;i++) str[i] = sb.charAt(i);
//     }
// }
```