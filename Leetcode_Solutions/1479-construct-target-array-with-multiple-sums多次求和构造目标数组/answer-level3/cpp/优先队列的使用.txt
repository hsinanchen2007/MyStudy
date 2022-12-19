class Solution {
public:
    bool isPossible(vector<int>& target) {
        //1设置大根堆
        //2.每次将较大的值放出，减去sum（这里要注意溢出的问题），target可以倍乘，可以如果出现负数就报错
        //如果发现最大值变为1了，那么认为正确
        priority_queue<int> my_q;
        long long sum=0;
        for(int i=0;i<target.size();i++)
        {
                sum+=target[i];
                my_q.push(target[i]);
        }//构建大根堆，同时实现求和，这里是减去其余数的和，可以用2*max-sum来实现

        while(1)
        {

            int max=my_q.top();
            int zancun=max;//这里是为了更新sum的值，这里我第一次写的时候犯了个错，忘记了更新sum，写程序的时候尤其要注意哪些变量是需要更新的
            if(max==1) return 1;//之所以当max为1的时候就可以终止，是因为1输入都大于0，且一旦变为负数就会报错
            if(max*2<=sum) return 0;//这里是变化为负数就报错
            max=max*2-sum;//这里实现max-其余数和的功能
            sum=zancun;//更新新一轮的sum值，其实就是上一轮的max
            my_q.pop();
            my_q.push(max);//更新堆
            


            
            
        }
    }
};

这道题主要有两个点。一个是要找到逆推的规律，另外一个是要想到优先队列这种数据结构。
逆推的规律是：1.每次找到最大的数，减去其他数的和变换为新的数。2.重复1，直到最大数为1此时返回1或者最大数比其余数之和小此时返回0.
当时做题的时候其实想到了这种方法，但是总是时间超时。当时是因为不知道优先队列这种数据结构，于是用vector实现了一下，结果写的非常麻烦。
因此，本题的第二个点就是优先队列，便于找出最大值，从而实现递推规律。