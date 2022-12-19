### 解题思路
注意几个细节
1. IP地址长度可能为1 0--> 9
2. IP地址长度可能为2 10--> 99
3. IP地址长度可能为3 100--> 255
我这里存储IP地址时，是分段存储的，所以当且仅当List的大小为4并且正好将s遍历结束，此时的IP地址才是有效的。
当List的大小为4，而s未遍历结束，则直接返回
当s遍历结束，List的大小不为4，也直接返回。

### 代码

```java
class Solution {
    
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        restore(s, 0, new ArrayList<>(), res);
        return res;
    }

    private void restore(String s,int next,List<String> res, List<String> result){
        int a = next;
        if (a == s.length() && res.size() == 4){
            StringBuilder sb = new StringBuilder();
            for (String re : res) {
                sb.append(re).append(".");
            }
            String string = sb.toString();
            result.add(string.substring(0,string.length()-1));
            return;
        }
        if (res.size() == 4 || a == s.length())
            return;
        if (a < s.length()){
            res.add(s.substring(a,a+1));
            restore(s, a+1, res, result);
            res.remove(res.size()-1);
        }
        if (a + 1 < s.length()){
            String sub = s.substring(a, a + 2);
            int i = Integer.parseInt(sub);
            if (i >= 10){
                res.add(sub);
                restore(s, a+2, res, result);
                res.remove(res.size() - 1);
            }
        }
        if (a + 2 < s.length()){
            String sub = s.substring(a, a + 3);
            int i = Integer.parseInt(sub);
            if (i >= 100 && i <= 255){
                res.add(sub);
                restore(s, a+3, res, result);
                res.remove(res.size() - 1);
            }
        }
    }
}
```