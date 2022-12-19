```
public class Solution {
    public int MaxSatisfied(int[] customers, int[] grumpy, int X) {
        int answer=0;
        //计算不开技能时的客户满意数量
        int i;
        for(i=0;i<customers.Length;i++){
            if(grumpy[i]==0){answer+=customers[i];}
        }

        //计算开技能能获得的额外顾客数量
        int skill=0;//这是“当前情况下”开了技能能获得的额外顾客数量
        int skill_max=0;//这是“所有情况下”开了技能能获得的额外顾客数量的最大值
        int j,k;
        for(j=0;j<=customers.Length-X;j++){
            for(k=j;k<j+X;k++){
                if(grumpy[k]==1){skill+=customers[k];}
            }
            if(skill>skill_max){skill_max=skill;}
            skill=0;//初始化
        }

        return answer+skill_max;//答案就是[不开技能得到的满意顾客数量]+[开技能得到的额外顾客满意数量]

    }
}
```