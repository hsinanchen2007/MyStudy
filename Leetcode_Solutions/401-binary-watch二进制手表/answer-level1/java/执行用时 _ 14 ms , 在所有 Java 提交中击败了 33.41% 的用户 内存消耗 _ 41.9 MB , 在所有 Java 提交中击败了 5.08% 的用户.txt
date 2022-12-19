### 解题思路
本题说白了就是判断给定一个数，对小时和分钟进行不停排列组合，去找到有多少符合条件的组合数，那么表亮则该位置为1，表灭则该位置为0，我们需要做的就是确定表亮的时候实际表示的是几点几分就可以了，这个解法中，n&(n-1)是关键，他帮助我们确认每个整数有几个1，这是很重要的也是最关键的一步。

### 代码

```java
class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> list = new LinkedList<String>();
        for(int i = 0;i<12;i++) {
            for(int j = 0;j<60;j++) {
                if(count(i)+count(j)==num) {
                    list.add(i+":"+(j<10?"0"+j:j));
                }
            }
        }
        return list;
    }
    public int count(int m) {
        int res = 0;
        while(m!=0) {
            m = m&(m-1);
            res++;
        }
        return res;
    }
}
```