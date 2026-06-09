思路：
1.两个字符串用'0'补齐短的一方,方便计算进位
2.由于当前位置的值取决于低位字符串运算的进位，因此可以抽象一个函数，使函数的返回值为进位值，回溯相加，将结果存在Stack中，或用StringBuffer反转

```
class Solution {
    
    StringBuffer sb = new StringBuffer();
    
    public String addBinary(String a, String b) {
        while(a.length() > b.length()){
            b = "0"+b;
        }
        while(a.length() < b.length()){
            a = "0"+a;
        }
        char c = add(a,b,0);
        if(c == '1')
            sb.append(c);
        return sb.reverse().toString();
    }
    
    //回溯
    public char add(String a, String b, int i){
        if(i == a.length() - 1){
            if(a.charAt(i) == '1' && b.charAt(i) == '1'){
                sb.append('0');
                return '1';
            }
            if(a.charAt(i) == '1' || b.charAt(i) == '1'){
                sb.append('1');
                return '0';
            }
            sb.append('0');
            return '0';
        }
        
        char result = add(a,b,i+1);
        int[] map = new int[2]; 
        map[result - '0']++;
        map[a.charAt(i) - '0']++;
        map[b.charAt(i) - '0']++;
        if(map[0] == 3){
            sb.append('0');
            return '0';
        }
        if(map[0] == 2){
            sb.append('1');
            return '0';
        }
        if(map[0] == 1){
            sb.append('0');
            return '1';
        }
        sb.append('1');
        return '1';
    }
}
```
