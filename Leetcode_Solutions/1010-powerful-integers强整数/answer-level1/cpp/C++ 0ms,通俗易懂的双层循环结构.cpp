思路
1. 双层循环遍历,找到符合要求的值,保存进数组
2. 对数组进行排序
3. 比较相邻的数,相同则去重
4. 返回数组
完成到这里,你会发现,还是通过不了,你需要考虑一些特殊情况
1. x=1,y=1,他们俩的n次方和,只有2,所以当bound>=2时,则返回2,但如果bound<2,则返回空
有些情况会根据你遍历的循环条件有关,我的循环条件就是平方和不大于bound,没有考虑到数学问题,但有利有弊



```
 vector<int> powerfulIntegers(int x, int y, int bound) 
    {
        if(x==1&&y==1){//特殊情况讨论
        if(bound==1||bound==0)
            return {};
        else
            return {2};
        }
        vector<int> vc(1,2);
        vc.erase(vc.begin());
        for(int i=0;pow(x,i)<=bound;i++)//循环查找
        {
           
            for(int j=0;pow(x,i)+pow(y,j)<=bound;j++){
                vc.push_back(pow(x,i)+pow(y,j));//插入元素
                if(y==1&&j==1)      //这个条件是为了避免y为1,x不等于时,不断加幂,会进入死循环
                    break;
            }
             if(x==1&&i==1){//也是为了避免x为1,y不等于1时,由于循环条件是<bound,但是不断加幂后,结果不变,会进入死循环
                break;   
            }   
            }
        sort(vc.begin(),vc.end());//排序
        
        for(int k=0;k<vc.size()-1;k++)//去重
        {   
            
            if(vc[k]==vc[k+1])
                vc.erase(vc.begin()+k);   
        }    
        return vc;
    }

```
