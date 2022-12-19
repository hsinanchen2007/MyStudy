    执行用时 :4 ms, 在所有 Java 提交中击败了99.97%的用户
    内存消耗 :36.2 MB, 在所有 Java 提交中击败了72.32%的用户

```
class Solution {
    public static int romanToInt(String s) {
        int[] a = new int[s.length()];
        for (int i=0;i<s.length();i++){
            char c = s.charAt(i);
            switch (c){
                case 'I':
                    a[i] = 1;
                    break;
                case 'V':
                    a[i] = 5;
                    break;
                case 'X':
                    a[i] = 10;
                    break;
                case 'L':
                    a[i] = 50;
                    break;
                case 'C':
                    a[i] = 100;
                    break;
                case 'D':
                    a[i] = 500;
                    break;
                case 'M':
                    a[i] = 1000;
                    break;
            }
        }
        int num = 0;
        for (int i = 0;i<a.length;i++){
            int l = a[i];
            if (i+1<a.length){
                int l1 = a[i+1];
                if (l<l1){
                    l=l1-l;
                    i++;
                }
            }
            num+=l;
        }
        return num;
    }
}
```
思路: 遍历每个字符并保存罗马数字所对应的整数，遍历整数数组，判断数组[i]是否小于[i+1],如果小于的话,当前数为[i+1]-[i],并跳过对[i+1]的遍历