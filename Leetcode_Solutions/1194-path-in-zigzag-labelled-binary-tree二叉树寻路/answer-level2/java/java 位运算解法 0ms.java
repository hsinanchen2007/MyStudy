### 解题思路
位运算解答。
![WX20200315-192000@2x.png](https://pic.leetcode-cn.com/342a143775ccdb7c10353bc848d86fb81352aa2353d02a2e6f885d3d467d597f-WX20200315-192000@2x.png)

### 代码

```java
class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        LinkedList<Integer> end = new LinkedList<>();
        end.add(label);
        if(label==1) {
            return end;
        }
        while (true){
            label = GetParent(label);
            end.addFirst(label);
            if(label==1) break;
        }

        return end;
    }
    //寻找最高位1，对应所在行
    public int findMax1(int i){
        if(i==1) return 0;
        int index = 0;
        while (true){
            index++;
            i = i>>1;
            if(i==1) return index;
        }
    }
    //获取数据坐标
    public int[] TranInt(int i){
        var a = findMax1(i);
        var ct = 1<<a;
        var b = i-(1<<a);
        if(a%2==1) b = ct - b -1;
        return new int[]{a,b};
    }
    //获取上级节点
    public int GetParent(int i){
        var tmp = TranInt(i);
        tmp[0] -=1;
        tmp[1] = tmp[1]/2;
        var rowCt = 1<<tmp[0];
        if(tmp[0]%2==1){
            tmp[1] = rowCt - tmp[1] -1;
        }
        return rowCt + tmp[1];
    }
}
```