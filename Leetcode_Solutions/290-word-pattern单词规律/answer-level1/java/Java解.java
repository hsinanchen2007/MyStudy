还是很菜，但是尽我所能了。思路还是很清晰的。一次映射即可，两次判断。
经过优化，时间可以达到1ms，但是空间复杂度还是较高，额外用了一个HashMap、KeySet和ArrayList。内存占用34MB。
思路：
一：将两个String转化为字符数组，遍历Pattern数组，将Pattern数组和str数组对应字符和字符串分别往Map中添加（注意数组越界条件控制）。
二：第一次判断，添加进Map的过程中，当即将填入的Key(Pattern数组的字符)已经存在，通过HashMap的get方法获取对应的字符串，判断与当前添加的字符串是否相同，若不相同，返回false;
若Key不存在，正常添加。
三：第二次判断，遍历添加完毕的HashMap,判断不同Key对应的字符串是否相同，若相同，与题意违背，返回false（题意要求pattern字符串的每个字符与str字符串经空格分隔后的字符串有双向连接
的对应规律，则不同的Pattern字符串中的字符对应唯一的字符串）。实现很简单，一次遍历即可。

代码：
```
class Solution {
    public boolean wordPattern(String pattern, String str) {
        if (pattern.length() == 0 || str.length() == 0) {
            return false;
        }
        String[] arr = str.split(" ");
        char[] arr1 =  pattern.toCharArray();
        if (arr.length != arr1.length) {
            return false;
        }

        HashMap<Character, String> map = new HashMap<>();

        for (int i = 0; i < arr1.length; i++) {
            if (i < arr.length) {
                if (map.containsKey(arr1[i])) {
                    if (!arr[i].equals(map.get(arr1[i]))) {
                        return false;
                    }
                } else {
                    map.put(arr1[i], arr[i]);
                }
            }
        }
        
        ArrayList<Character> list = new ArrayList<>();
        for (Character key : map.keySet()) {
            list.add(key);
        }
        Character key0 = list.get(0);
        for (int i = 1; i < list.size(); i++) {
            if (map.get(key0).equals(map.get(list.get(i)))) {
                return false;
            }
        }

        return true;
    }
}
```
