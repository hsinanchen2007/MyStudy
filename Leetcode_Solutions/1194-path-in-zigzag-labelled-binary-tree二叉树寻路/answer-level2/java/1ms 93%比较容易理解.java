### 解题思路
主要分成5大部分：
1.把头结点1放入list，因为不管哪个点最终都需要1这个节点，如果label是1，直接返回
2.求出来label是在哪一行，用的log2求的
3.把label的序号转化为没有任何翻转的情况下的值
4.求出来所有的没有任何翻转的节点位置
5.把奇数行的节点翻转过来，最后返回

### 代码

```java
class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        List<Integer>res=new ArrayList<>();
        res.add(1);
        if (label==1)
            return res;
        
        int last=(int)Math.floor(Math.log(label)/Math.log(2));
        
        if ((last&1)==1) {
            int rightLen=(1<<last+1)-label-1;
            label =(1<<last)+rightLen;
        }
        
        while (label!=1){
            res.add(1,label);
            label=label>>1;
        }
        
        for (int i=0;i<res.size();i++){
            if ((i&1)==1){
                int rightLen=(1<<i+1)-res.get(i)-1;
                res.set(i,(1<<i)+rightLen);
            }
        }
        return res;
    }
}
```