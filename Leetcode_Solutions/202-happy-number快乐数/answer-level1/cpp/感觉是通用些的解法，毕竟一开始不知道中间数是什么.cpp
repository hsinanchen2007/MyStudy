```
class Solution {
public:
    bool isHappy(int n) {
        set<int> a;  //储存计算过的数，如果当前的值在set集合里，说明会进入循环
                     //各位的平方和永远不可能是1，为防止程序永远循环需要这一步
        int sum=n;
        while((sum!=1)&&(a.find(sum)==a.end()))  //循环条件:不是快乐数，且未出现过
        {
            a.insert(sum);    //插入上一轮的结果
            n=sum;
            sum=0;
            do
            {
                sum+=pow(n%10,2);
                n/=10;
            }while(n);
        }
        if(sum==1) return true;
        return false;
    }
};
```