利用字符串的indexOf函数，遍历一遍所拥有的石头，判断宝石中是否含有该石头
indexOf函数返回-1，则说明宝石中不包含该石头
```
class Solution {
    public int numJewelsInStones(String J, String S) {
        char[] ch = S.toCharArray();
        int count = 0;
        for(int i=0;i<ch.length;i++){
            if(J.indexOf(ch[i])>=0)
                count++;
        }
        return count;
    }
}
```
