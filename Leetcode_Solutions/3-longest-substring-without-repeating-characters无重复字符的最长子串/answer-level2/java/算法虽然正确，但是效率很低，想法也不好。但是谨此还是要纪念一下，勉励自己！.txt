### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.equals("")) { //如果输入为空字符串，则返回0
            return 0;
        }
        List<Integer> list = new ArrayList<>();
        int len = s.length();
        int count = 1;
        for (int i = 0; i < len; i++){
            /*if (count >= s.substring(i).length()){
                return count;
            }*/

            count = 1; //count重新置为1
            for (int j = i + 1; j < len; j++){
                if (!s.substring(i, i + count).contains(s.charAt(j) +"")){
                    count++;
                    list.add(count); //将从下标为i的字符开始计数的最长不重复子串的长度存入list集合
                }else {
                    list.add(count); //将从下标为i的字符开始计数的最长不重复子串的长度存入list集合
                    break;
                }
            }
        }
        Collections.sort(list);
        System.out.println("list = " + list);
        //下面的return语句，是为了防止形如"a"或"b"等单个字符的例子
        return list.size() == 0 ? 1 : list.get(list.size() - 1);
    }
}
```