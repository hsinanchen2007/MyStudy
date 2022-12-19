    int maxProfit(vector<int>& prices) {
    //         if(prices.empty())
    //             return 0;     
    //         int dif=0;
    //         for(int i=0;i<prices.size();i++)
    //         {
    //             int min=prices[i];//选择第一个数       
    //             for(int j=i+1;j<prices.size();j++)//后面的每一个数与第一个数比较
    //             {
    //                 dif=((prices[j]-prices[i])>dif)?(prices[j]-prices[i]):dif;
    //             }
    //         }
    //         return dif;
            //以上是暴力解法
            //以下使用栈。
            if(prices.empty())
                return 0;   
            stack<int> s;
            int dif=0;
            s.push(prices[0]);
            for(int i=1;i<prices.size();i++)
            {
                //如果小于，栈顶元素，则栈顶元素出栈，该数入栈
                if(prices[i]<s.top())
                {
                    s.pop();
                    s.push(prices[i]);
                }
                //如果大于栈顶元素，则计算差值，并比较。
                else if(prices[i]>s.top())
                    dif=((prices[i]-s.top())>dif)?(prices[i]-s.top()):dif;
            }     
            return dif;          
        }


1.暴力解法
    思路简单，每次取第一个数，求后面的数与第一个数的差值。最后得到最大差值。
2.利用栈
    第一个数入栈，栈内永远只有一个数
    比较后面的数，如小于栈顶，则栈顶元素先出栈，该数入栈；如大于栈顶，则求差值
    直到最后一个数完，得到最大差值