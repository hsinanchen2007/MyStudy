执行用时 :6 ms, 在所有 java 提交中击败了99.20%的用户
内存消耗 :48.5 MB, 在所有 java 提交中击败了100.00%的用户

设从第1棵树到第k棵树的最大采果数量为f(k)，而以将第k棵树的水果采入为前提条件的最大采果数为g(k),则有f(k+1)=MAX(f(k),g(k+1))。
初始条件下f(1)=1，f(2)=2，为了计算g(k)，添加一个计数器totalCurrent，初始值为0。
从第1棵树出发，如果遇到的水果种类一直不大于2，则totalCurrent++，当遇到第三种水果时，首先更新f(k-1)，然后第三种水果与其之前紧邻且连续的那种水果的数量和continueFruitNum+1即为新的totalCurrent

```
public class Solution {
    public int totalFruit(int[] tree){
        if(tree.length<3)return tree.length;
        int currentFruitType=-1;
        int totalMax=0;
        int totoalCurrent=0;
        int fruitTypeNum=0;
        int fruitType1=-1;
        int fruitType2=-1;
        int continueFruitNum=0;

        for(int i=0;i<tree.length;i++){
            if(tree[i]==currentFruitType){//水果种类和左邻相同，采果无脑+1
                continueFruitNum++;
                totoalCurrent++;
            }else{
                if(tree[i]==fruitType1||tree[i]==fruitType2){//水果种类和左邻不同，但是仍是前两种水果之一，也继续采果
                    totoalCurrent++;
                }else{//水果种类不在记录在案的两种水果之内
                    if(fruitTypeNum<2){//已记录的水果种类不大于2，继续采果
                        totoalCurrent++;
                        fruitTypeNum++;
                    }else{//这的确是第三种水果，结算在此之前的两种水果采集数量是否足够大（大于max记录），足够大则更新记录，不足够大则抛弃
                          //然后加入第三种水果，与左邻的那种水果合计为新的采集方案
                        totalMax=totoalCurrent>totalMax?totoalCurrent:totalMax;
                        totoalCurrent=continueFruitNum+1;
                    }
                    fruitType1=currentFruitType;//更新记录水果种类1
                    fruitType2=tree[i];//更新记录水果种类2
                }
                currentFruitType=tree[i];//更新左邻记录
                continueFruitNum=1;//更新左邻连续采果的计数
            }
            if(i==tree.length-1)totalMax=totoalCurrent>totalMax?totoalCurrent:totalMax;//最后一棵树，即使其不是第三种果树也必须结算
        }

        return totalMax;
    }
}
```
