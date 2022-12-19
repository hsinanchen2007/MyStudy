基本思路：三种情况
1.考虑左边极端情况，也就是第一次出现1的时候，左边有多少个0，那么最远距离就是0的个数
2.考虑右边极端情况，一直到最右边最后一个元素都是0，0的长度就是最远距离
3.考虑中间的情况，也就是0的个数被夹在两个1中间，毫无疑问，那么0的个数的一半+1就是距离。
这里需要说明一下第三种情况，我们统一给0的个数再加1，这样可以避免计数器为0的情况，也就是避免判断1连续的情况
```
int maxDistToClosest(int* seats, int seatsSize){
    int max=0,countzero=0,i,posi=-1;
    for(i=0;i<seatsSize;i++)
    {
        if(seats[i]==1)//有人坐着
        {
            if(posi==-1)//第一次出现有人坐着,即左边极端的情况
                    max=i;
            else if(countzero>0)//并非第一次出现有人坐着
            {   
                    countzero++;
                if(countzero/2>max)//出现符合要求的
                {
                    max=countzero/2;
                }
            }
            countzero=0;
            posi=i;
        }
        else if(seats[i]==0)//座位是空着的
            countzero++;
    }
    if(countzero>max)//处理右边的极端情况
        max=countzero;
    return max;
}
```
