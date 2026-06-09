### 解题思路
![1584836508(1).png](https://pic.leetcode-cn.com/19065e4986f29e44396a061965573237c0feac91c42b6bdb6fc91aef75286d13-1584836508\(1\).png)
用一个二维数组存储必然超空间，我卡在那里很，所以用map，这样保证了没有多余空间。
仔细观察可以发现只有第3到倒数第2个位置有影响，并且可以将其分成四个区域，用二进制表示，0b0000。
遍历reservedSeats，如果没有这个key就填0，否则将value和新加入的位置做或运算。
最后遍历一遍map，由于map只记录了受到影响的位置，因此在最后还要用n-map.size()把空的都算上。

### 代码

```java
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer,Integer> map=new HashMap<>();
        
        int count=0;
        for(int[] s:reservedSeats){
            int len=s[0];
            if(s[1]>=2&&s[1]<=3)
                map.put(len,map.getOrDefault(len,0)|0b1000);
            else if(s[1]>=4&&s[1]<=5)
                map.put(len,map.getOrDefault(len,0)|0b0100);
            else if(s[1]>=6&&s[1]<=7)
                map.put(len,map.getOrDefault(len,0)|0b0010);
            else if(s[1]>=8&&s[1]<=9)
                map.put(len,map.getOrDefault(len,0)|0b0001);
        }
        for(int key:map.keySet()){
            int b=map.get(key);
            if((b>=1&&b<=4)||(b>=8&&b<=9)||b==12)
                count++;
        }
        if(n>map.size())
            count=count+2*(n-map.size());
        return count;
    }
}
```