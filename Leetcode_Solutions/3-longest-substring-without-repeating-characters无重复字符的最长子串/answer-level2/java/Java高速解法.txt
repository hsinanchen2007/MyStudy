### 解题思路
执行用时 :2 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :39.5 MB, 在所有 Java 提交中击败了8.92%的用户

1.对于s.length()==0的情况直接返回即可
2.定义[start,end)来表示这个substring，初始化状态即认为第一个字符为目标substring，即star0,end=1
3.遍历完所有剩余字符，查看剩余字符是否与已知最长substring发生重复，pos返回-1即不重复，否则返回找到的重复位置
4.在每步更新[start,end)来表示新的最长字符串
5.返回end-start即为结果

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length()==0) return 0;
        int start=0, end=1;
        int maxlen = 0;
        for (int i=end;i<s.length();i++) {
            char c = s.charAt(i);
            int pos = -1;
            for (int j=start;j<end;j++) {
                if (s.charAt(j)==c) {
                    pos = j;
                    break;
                }
            } 
            if (pos>=0) {
                maxlen = end-start>maxlen?end-start:maxlen;
                start = pos+1;
            }
            end = i+1;
        }
        maxlen = end-start>maxlen?end-start:maxlen;
        return maxlen;
    }

    public int find(int start,int end, String s, char ch) {
        for (int i=start;i<end;i++) {
            if (s.charAt(i)==ch) {
                return i;
            }
        }
        return -1;
    }

}
```