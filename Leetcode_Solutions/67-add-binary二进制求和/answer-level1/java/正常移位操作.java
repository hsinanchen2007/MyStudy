```
class Solution {
    public String addBinary(String a, String b) {
        int index1 = a.length() - 1, index2 = b.length() - 1;
        int add = 0;//进位
        StringBuilder res = new StringBuilder();
        while (index1 >= 0 || index2 >= 0) {
            int num1 = index1 >= 0 ? a.charAt(index1) - '0' : 0;
            int num2 = index2 >= 0 ? b.charAt(index2) - '0' : 0;
            int val = (num1 + num2 + add) % 2;
            res.insert(0, val);

            add = (num1 + num2 + add) / 2;

            index1--;
            index2--;
        }

        if(add > 0){
            res.insert(0, add);
        }
        return res.toString();
    }
}
```
