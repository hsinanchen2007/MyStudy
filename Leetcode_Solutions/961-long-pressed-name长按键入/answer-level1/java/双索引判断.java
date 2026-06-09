写题时候想的解法比较复杂，第一次写。
我的想法是，通过两个索引判断当前两个索引位的值是否相等，不相等返回false，相等判断两个字符数组的重复字母数量是否相同，若相同，则向后移动至下一个不重复字母，再次重复判断，重复到当有一个数组索引完毕，跳出循环，判断当前两个索引的值是否都处于两个字符数组的最后一位，为检测两数组除重复字母外是否是相同长度，若都处于最后一位，则返回true，否则返回false。

```
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        char[] nameArry = name.toCharArray();
        char[] typedArry = typed.toCharArray();
        int nameindex = 0;
        int typedindex = 0;
        int nameLength = nameArry.length;
        int typedLength = typedArry.length;
        while (nameindex<nameLength && typedindex<typedLength){
            char n = nameArry[nameindex];
            char t = typedArry[typedindex];
            if (n == t) {
                int samen = 0;
                int samet = 0;
                while (nameindex < nameLength) {
                    if (nameindex + 1 == nameLength){
                        nameindex ++;
                        break;
                    }
                    if (nameArry[nameindex] == nameArry[nameindex + 1]) {
                        nameindex++;
                        samen++;
                    }else{
                        nameindex++;
                        break;
                    }
                }
                while ((typedindex ) < typedLength) {
                    if (typedindex + 1 == typedLength){
                        typedindex++;
                        break;
                    }
                    if (typedArry[typedindex] == typedArry[typedindex + 1]) {
                        typedindex++;
                        samet++;
                    }else{
                        typedindex++;
                        break;
                    }
                }
                if (samen > samet) return false;
            }else {
                return false;
            }
        }
        return  typedindex == typedLength && nameindex  == nameLength;
    }
}

```
