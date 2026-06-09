
基本思路，建造一个80000空间的桶来存放目标数字，把重复数字存起来，再遍历一遍重复数字，依次把重复数字移动到没放东西的桶中，这样一共只要遍历一遍目标数组和重复数组就够了。
```
public int minIncrementForUnique(int[] A) {
            int[] T=new int[80001];//由于0<=A[i]<40000,则可以用最有效率的桶插法来排序。
            int[] Repeat=new int[40001];//重复的数字
            int repeatCount=0;//重复的数字的数量
            int moveCount=0;//总移动步数
            for(int i=0;i<A.length;i++)//遍历一遍数组，放入对应的值得桶中
            {
                if(T[A[i]]==0)//这个桶没有值，放入 
                {
                    T[A[i]]=1;
                }
                else//这个桶已经有值,则放入重复数组中待移动
                {
                    Repeat[repeatCount++]=A[i];
                }
            }
            for(int i=0;i<repeatCount;i++)//遍历重复数组，遍历每个数，计算总移动步数
            {
                int curReatNum=Repeat[i];
                while(T[curReatNum]==1)//找出这个桶位置开始没有放东西的桶
                {
                    curReatNum++;//移动桶的位置
                    moveCount++;//移动步数
                }
                T[curReatNum]=1;//找到没放入东西的桶，放入数字

            }
            return moveCount;
    }
```
