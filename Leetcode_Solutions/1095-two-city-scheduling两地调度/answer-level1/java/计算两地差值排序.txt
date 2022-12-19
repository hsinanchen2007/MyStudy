
1.计算每个人去A地和B地费用之差，对差值进行排序，排前一半（即去A地更加划算的）去A，排后一半的去B。
2.将去A地人的费用之差加起来记为gap1,去B地的费用之差记为gap2。
3.在最后计算的时候假设去A地的人合计费用为w1,那这些人如果再去B地则需要w1-gap1;同理设去B地的人合计费用w2,那这些人若要再去A地则要花w2+gap2;
4.计算所有人既去A又去B要花费total,则有公式w1+w1-gap1+w2+w2+gap2=total,w1+w2=(total+gap1-gap2)/2;

```
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int[] cost_gap = new int[costs.length];//计算A-B的差值
        for(int i=0;i<costs.length;++i){
            cost_gap[i]=costs[i][1]-costs[i][0];//计算去A地费用和去B费用的差值
        }
        Arrays.sort(cost_gap);
        int gap1=0,gap2=0;
        for(int i=0;i<cost_gap.length;++i){
            if(i<cost_gap.length/2) gap1+=cost_gap[i];//前一半gap1,后一半gap2;
            else gap2+=cost_gap[i];
        }
        int total=0;
        for(int i=0;i<costs.length;++i){
            total+=(costs[i][0]+costs[i][1]);//计算所有人既去A又去B要花费的总额
        }
        return (total+gap1-gap2)/2;//公式
    }
}
```
