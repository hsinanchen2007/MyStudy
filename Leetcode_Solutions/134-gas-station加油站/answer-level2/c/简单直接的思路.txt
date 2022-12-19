//写的时候多用几个if注意一下环路问题就好
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    
    int answer=-1;
    int i=0;//从0号开始进行尝试
    int t=0;//一会儿用来记录车所到达的站点
    while(i<gasSize)
    {
        int temp=0;//初始油箱为空
        if(gas[i]<cost[i]) //若一出发gas就小于cost则跳过
        {
            i++;
            continue;
        }
        else
        {
            temp=temp+gas[i]-cost[i];//到达第二站时的油箱情况(还未加第二站的油)          
            if(i<gasSize-1) t=i+1;//需记录出发点,故用变量t表示所到达的站点
            else t=0;//如果从最后一个站点出发的,则第一站是到达号站点
            int cnt=1;//记录走过了几个站
            while(temp>=0&&cnt<=gasSize)
            {
                temp=temp+gas[t]-cost[t];//加上t站的油,并到达下一站
                if(t+1<gasSize)
                {
                    t++;
                }
                else
                {
                    t=0;
                }
                cnt++;
            }
        }
        if(temp>=0)//判断最后是否能够到达出发站 
        {
            answer=i;
            i++;
        }
        else 
        {   
            i++;
            continue;           
        }
    }
    return answer;
}
```